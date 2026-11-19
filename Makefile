CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -Iinclude -MMD -MP
SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:src/%.c=build/%.o)
INSTALL_PREFIX ?= $(HOME)/.local
LIBRARY = build/libccutils.a

.PHONY: all install clean

all: $(LIBRARY)

$(LIBRARY): $(OBJECTS)
	ar rcs $@ $^

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build

install: $(LIBRARY)
	mkdir -p $(INSTALL_PREFIX)/include/ccutils $(INSTALL_PREFIX)/lib
	cp include/*.h $(INSTALL_PREFIX)/include/ccutils/
	cp $(LIBRARY) $(INSTALL_PREFIX)/lib/

clean:
	rm -rf build

-include $(OBJECTS:.o=.d)