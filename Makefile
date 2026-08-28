CC = gcc

CFLAGS = -Wall -Wextra -I./src
LDFLAGS = -lraylib -lm

TARGET = bin/Pong/pong
RESOURCES_SRC = resources
RESOURCES_DST = bin/Pong/resources

rwildcard = $(foreach d,$(wildcard $1*/),$(call rwildcard,$d,$2)) \
            $(wildcard $1$2)

SRC = $(call rwildcard,src/,*.c)

.PHONY: all clean resources

all: $(TARGET) resources

$(TARGET): $(SRC)
	@mkdir -p bin/Pong
	$(CC) $(CFLAGS) -o $@ $(SRC) $(LDFLAGS)

resources:
	@mkdir -p $(RESOURCES_DST)
	@cp -r $(RESOURCES_SRC)/. $(RESOURCES_DST)/

clean:
	rm -rf bin