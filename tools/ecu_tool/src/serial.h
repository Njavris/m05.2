#ifndef ECU_TOOL_SERIAL_H
#define ECU_TOOL_SERIAL_H

#include <stddef.h>
#include <stdint.h>

typedef struct serial_port serial_port;

serial_port *serial_open(const char *path, unsigned baud,
                         char *err, size_t errlen);
void serial_close(serial_port *port);
int serial_flush(serial_port *port);
int serial_write_all(serial_port *port, const uint8_t *data, size_t len);
int serial_read(serial_port *port, uint8_t *data, size_t maxlen,
                unsigned timeout_ms);
int serial_set_break(serial_port *port, int enabled);
void serial_sleep_ms(unsigned ms);

#endif
