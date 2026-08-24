CC = gcc

CFLAGS = -Wall -Wextra -I./src
LDFLAGS = -lraylib -lm

TARGET = bin/pong

rwildcard = $(foreach d,$(wildcard $1*/),$(call rwildcard,$d,$2)) \
            $(wildcard $1$2)

SRC = $(call rwildcard,src/,*.c)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p bin
	$(CC) $(CFLAGS) -o $@ $(SRC) $(LDFLAGS)

clean:
	rm -f $(TARGET)