CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -Iinclude
SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:src/%.c=build/%.o)
INSTALL_PREFIX ?= $(HOME)/.local

install: build/libplib.a
	mkdir -p $(INSTALL_PREFIX)/include $(INSTALL_PREFIX)/lib
	cp include/*.h $(INSTALL_PREFIX)/include/
	cp build/ccutils.a $(INSTALL_PREFIX)/lib/

build/ccutils.a: $(OBJECTS)
	ar rcs $@ $^

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build

clean:
	rm -rf build