CC       ?= gcc
CFLAGS   ?= -std=c11 -O2 -Wall -Wextra -Wpedantic
CPPFLAGS ?= -Iinclude
LDFLAGS  ?=
DUMP     ?= ../dumps/mash_dump.bin

SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:.c=.o)
BIN  := firmware_model

.PHONY: all test demo clean repro collect maps fuel-map reconstruction

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

test: $(BIN)
	./$(BIN) --test $(DUMP)

demo: $(BIN)
	./$(BIN) $(DUMP)

# Byte-exact reproduction of the original 256 KB image from the generated
# assembly listing. No C166 toolchain is required.
repro:
	mkdir -p build
	python3 tools/assemble_listing.py asm/firmware.s build/firmware_rebuilt.bin
	python3 tools/compare_image.py $(DUMP) build/firmware_rebuilt.bin

collect:
	python3 tools/collect_ghidra.py

maps:
	python3 tools/visualize_maps.py --dump $(DUMP) --out ../artifacts/maps
	python3 tools/fuel_map_viewer.py --dump $(DUMP) --out ../artifacts/maps/fuel_map.html

fuel-map:
	python3 tools/fuel_map_viewer.py --dump $(DUMP) --out ../artifacts/maps/fuel_map.html

reconstruction:
	python3 tools/build_reconstruction.py

clean:
	rm -f $(OBJS) $(BIN)
	rm -rf build
