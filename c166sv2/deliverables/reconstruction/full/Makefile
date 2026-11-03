.PHONY: all test catalog clean

all:
	cmake -S . -B build
	cmake --build build

catalog:
	python3 tools/build_catalog.py
	python3 tools/summarize_hud_logs.py

test: all
	ctest --test-dir build --output-on-failure

clean:
	rm -rf build
