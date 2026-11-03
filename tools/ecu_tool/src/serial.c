#ifndef _WIN32
#ifdef __linux__
#define _DEFAULT_SOURCE
#define _POSIX_C_SOURCE 200809L
#endif
#endif

#include "serial.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>

struct serial_port {
    HANDLE handle;
    char path[256];
};

static void set_error(char *err, size_t errlen, const char *msg)
{
    if (err && errlen) {
        snprintf(err, errlen, "%s", msg);
    }
}

serial_port *serial_open(const char *path, unsigned baud,
                         char *err, size_t errlen)
{
    char full[300];
    HANDLE h;
    DCB dcb;
    COMMTIMEOUTS timeouts;
    serial_port *port;

    if (!path || !*path) {
        set_error(err, errlen, "empty serial path");
        return NULL;
    }
    if (strncmp(path, "\\\\.\\", 4) == 0) {
        snprintf(full, sizeof(full), "%s", path);
    } else {
        snprintf(full, sizeof(full), "\\\\.\\%s", path);
    }
    h = CreateFileA(full, GENERIC_READ | GENERIC_WRITE, 0, NULL,
                    OPEN_EXISTING, 0, NULL);
    if (h == INVALID_HANDLE_VALUE) {
        set_error(err, errlen, "cannot open COM port");
        return NULL;
    }
    memset(&dcb, 0, sizeof(dcb));
    dcb.DCBlength = sizeof(dcb);
    if (!GetCommState(h, &dcb)) {
        set_error(err, errlen, "GetCommState failed");
        CloseHandle(h);
        return NULL;
    }
    dcb.BaudRate = (DWORD)baud;
    dcb.ByteSize = 8;
    dcb.Parity = NOPARITY;
    dcb.StopBits = ONESTOPBIT;
    dcb.fBinary = TRUE;
    dcb.fParity = FALSE;
    dcb.fOutxCtsFlow = FALSE;
    dcb.fOutxDsrFlow = FALSE;
    dcb.fDtrControl = DTR_CONTROL_DISABLE;
    dcb.fDsrSensitivity = FALSE;
    dcb.fOutX = FALSE;
    dcb.fInX = FALSE;
    dcb.fRtsControl = RTS_CONTROL_DISABLE;
    if (!SetCommState(h, &dcb)) {
        set_error(err, errlen, "SetCommState failed");
        CloseHandle(h);
        return NULL;
    }
    timeouts.ReadIntervalTimeout = 20;
    timeouts.ReadTotalTimeoutMultiplier = 0;
    timeouts.ReadTotalTimeoutConstant = 1000;
    timeouts.WriteTotalTimeoutMultiplier = 0;
    timeouts.WriteTotalTimeoutConstant = 1000;
    if (!SetCommTimeouts(h, &timeouts)) {
        set_error(err, errlen, "SetCommTimeouts failed");
        CloseHandle(h);
        return NULL;
    }
    PurgeComm(h, PURGE_RXCLEAR | PURGE_TXCLEAR);
    port = (serial_port *)calloc(1, sizeof(*port));
    if (!port) {
        set_error(err, errlen, "out of memory");
        CloseHandle(h);
        return NULL;
    }
    port->handle = h;
    snprintf(port->path, sizeof(port->path), "%s", path);
    return port;
}

void serial_close(serial_port *port)
{
    if (!port) {
        return;
    }
    CloseHandle(port->handle);
    free(port);
}

int serial_flush(serial_port *port)
{
    if (!port) {
        return -1;
    }
    PurgeComm(port->handle, PURGE_RXCLEAR | PURGE_TXCLEAR);
    return 0;
}

int serial_write_all(serial_port *port, const uint8_t *data, size_t len)
{
    DWORD written = 0;
    size_t offset = 0;

    if (!port || !data) {
        return -1;
    }
    while (offset < len) {
        if (!WriteFile(port->handle, data + offset, (DWORD)(len - offset),
                       &written, NULL)) {
            return -1;
        }
        if (written == 0) {
            return -1;
        }
        offset += written;
    }
    return 0;
}

int serial_read(serial_port *port, uint8_t *data, size_t maxlen,
                unsigned timeout_ms)
{
    DWORD got = 0;
    COMMTIMEOUTS timeouts;
    size_t total = 0;
    ULONGLONG deadline;

    if (!port || !data || maxlen == 0) {
        return -1;
    }
    timeouts.ReadIntervalTimeout = 20;
    timeouts.ReadTotalTimeoutMultiplier = 0;
    timeouts.ReadTotalTimeoutConstant = timeout_ms;
    timeouts.WriteTotalTimeoutMultiplier = 0;
    timeouts.WriteTotalTimeoutConstant = 1000;
    SetCommTimeouts(port->handle, &timeouts);
    deadline = GetTickCount64() + timeout_ms;
    while (total < maxlen) {
        DWORD want = (DWORD)(maxlen - total);
        if (!ReadFile(port->handle, data + total, want, &got, NULL)) {
            return total > 0 ? (int)total : -1;
        }
        total += got;
        if (total > 0) {
            break;
        }
        if (GetTickCount64() >= deadline) {
            break;
        }
    }
    return (int)total;
}

int serial_set_break(serial_port *port, int enabled)
{
    if (!port) {
        return -1;
    }
    if (enabled) {
        return SetCommBreak(port->handle) ? 0 : -1;
    }
    return ClearCommBreak(port->handle) ? 0 : -1;
}

void serial_sleep_ms(unsigned ms)
{
    Sleep(ms);
}

#else

#include <fcntl.h>
#include <poll.h>
#include <sys/ioctl.h>
#include <time.h>
#include <unistd.h>
#ifdef __linux__
#include <asm/termbits.h>
#include <asm/ioctls.h>
#else
#include <termios.h>
#endif
#ifdef __APPLE__
#include <IOKit/serial/ioss.h>
#endif

struct serial_port {
    int fd;
    char path[256];
};

static void set_error(char *err, size_t errlen, const char *msg)
{
    if (err && errlen) {
        snprintf(err, errlen, "%s", msg);
    }
}

#ifndef __linux__
static speed_t baud_constant(unsigned baud)
{
    switch (baud) {
    case 9600: return B9600;
#ifdef B10400
    case 10400: return B10400;
#endif
    case 19200: return B19200;
    case 38400: return B38400;
#ifdef B57600
    case 57600: return B57600;
#endif
#ifdef B115200
    case 115200: return B115200;
#endif
    default: return 0;
    }
}
#endif

serial_port *serial_open(const char *path, unsigned baud,
                         char *err, size_t errlen)
{
    int fd;
    serial_port *port;

    if (!path || !*path) {
        set_error(err, errlen, "empty serial path");
        return NULL;
    }
    fd = open(path, O_RDWR | O_NOCTTY | O_NONBLOCK);
    if (fd < 0) {
        set_error(err, errlen, strerror(errno));
        return NULL;
    }
#ifdef __linux__
    {
        struct termios2 tio;
        if (ioctl(fd, TCGETS2, &tio) != 0) {
            set_error(err, errlen, "TCGETS2 failed");
            close(fd);
            return NULL;
        }
        tio.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR |
                         IGNCR | ICRNL | IXON | IXOFF | IXANY);
        tio.c_oflag &= ~OPOST;
        tio.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
        tio.c_cflag &= ~(CBAUD | CSIZE | PARENB | CSTOPB);
#ifdef CRTSCTS
        tio.c_cflag &= ~CRTSCTS;
#endif
        tio.c_cflag |= BOTHER | CS8 | CLOCAL | CREAD;
        tio.c_ispeed = baud;
        tio.c_ospeed = baud;
        tio.c_cc[VMIN] = 0;
        tio.c_cc[VTIME] = 0;
        if (ioctl(fd, TCSETS2, &tio) != 0) {
            set_error(err, errlen, "TCSETS2 failed");
            close(fd);
            return NULL;
        }
    }
#else
    {
        struct termios tio;
        speed_t speed = baud_constant(baud);
#ifdef __APPLE__
        if (speed == 0) {
            speed = B9600;
        }
#else
        if (speed == 0) {
            set_error(err, errlen, "unsupported baud rate");
            close(fd);
            return NULL;
        }
#endif
        if (tcgetattr(fd, &tio) != 0) {
            set_error(err, errlen, "tcgetattr failed");
            close(fd);
            return NULL;
        }
        tio.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR |
                         IGNCR | ICRNL | IXON | IXOFF | IXANY);
        tio.c_oflag &= ~OPOST;
        tio.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
        tio.c_cflag &= ~(PARENB | CSTOPB | CSIZE);
#ifdef CRTSCTS
        tio.c_cflag &= ~CRTSCTS;
#endif
        tio.c_cflag |= CS8 | CLOCAL | CREAD;
        tio.c_cc[VMIN] = 0;
        tio.c_cc[VTIME] = 0;
        if (cfsetispeed(&tio, speed) != 0 || cfsetospeed(&tio, speed) != 0) {
            set_error(err, errlen, "cfsetispeed/cfsetospeed failed");
            close(fd);
            return NULL;
        }
        if (tcsetattr(fd, TCSANOW, &tio) != 0) {
            set_error(err, errlen, "tcsetattr failed");
            close(fd);
            return NULL;
        }
#ifdef __APPLE__
        {
            speed_t actual = (speed_t)baud;
            if (ioctl(fd, IOSSIOSPEED, &actual) != 0) {
                set_error(err, errlen, "IOSSIOSPEED failed");
                close(fd);
                return NULL;
            }
        }
#endif
    }
#endif
#ifdef __linux__
    ioctl(fd, TCFLSH, TCIOFLUSH);
#else
    tcflush(fd, TCIOFLUSH);
#endif
    port = (serial_port *)calloc(1, sizeof(*port));
    if (!port) {
        set_error(err, errlen, "out of memory");
        close(fd);
        return NULL;
    }
    port->fd = fd;
    snprintf(port->path, sizeof(port->path), "%s", path);
    return port;
}

void serial_close(serial_port *port)
{
    if (!port) {
        return;
    }
    close(port->fd);
    free(port);
}

int serial_flush(serial_port *port)
{
    if (!port) {
        return -1;
    }
#ifdef __linux__
    ioctl(port->fd, TCFLSH, TCIOFLUSH);
#else
    tcflush(port->fd, TCIOFLUSH);
#endif
    return 0;
}

int serial_write_all(serial_port *port, const uint8_t *data, size_t len)
{
    size_t offset = 0;

    if (!port || !data) {
        return -1;
    }
    while (offset < len) {
        ssize_t n = write(port->fd, data + offset, len - offset);
        if (n < 0) {
            if (errno == EINTR) {
                continue;
            }
            if (errno == EAGAIN) {
                struct pollfd pfd;
                pfd.fd = port->fd;
                pfd.events = POLLOUT;
                if (poll(&pfd, 1, 1000) <= 0) {
                    return -1;
                }
                continue;
            }
            return -1;
        }
        if (n == 0) {
            return -1;
        }
        offset += (size_t)n;
    }
    return 0;
}

int serial_read(serial_port *port, uint8_t *data, size_t maxlen,
                unsigned timeout_ms)
{
    struct pollfd pfd;
    ssize_t n;
    int pr;

    if (!port || !data || maxlen == 0) {
        return -1;
    }
    pfd.fd = port->fd;
    pfd.events = POLLIN;
    pfd.revents = 0;
    pr = poll(&pfd, 1, (int)timeout_ms);
    if (pr < 0) {
        if (errno == EINTR) {
            return 0;
        }
        return -1;
    }
    if (pr == 0) {
        return 0;
    }
    n = read(port->fd, data, maxlen);
    if (n < 0) {
        if (errno == EAGAIN || errno == EINTR) {
            return 0;
        }
        return -1;
    }
    return (int)n;
}

int serial_set_break(serial_port *port, int enabled)
{
    if (!port) {
        return -1;
    }
#if defined(TIOCSBRK) && defined(TIOCCBRK)
    return ioctl(port->fd, enabled ? TIOCSBRK : TIOCCBRK, 0);
#else
    if (enabled) {
        return tcsendbreak(port->fd, 0);
    }
    return 0;
#endif
}

void serial_sleep_ms(unsigned ms)
{
    struct timespec ts;
    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (long)(ms % 1000) * 1000000L;
    while (nanosleep(&ts, &ts) != 0 && errno == EINTR) {
    }
}

#endif
