CC = gcc

CFLAGS = -Wall -Wextra -I./src
LDFLAGS = -lraylib -lm

TARGET = bin/Pong/pong
RESOURCES_SRC = resources
RESOURCES_DST = bin/Pong/resources

SRC := $(shell find src -type f -name '*.c')

ifeq ($(OS),Windows_NT)
    LDFLAGS += -Iinclude -Llib -lgdi32 -lwinmm
endif

.PHONY: all clean resources

all: $(TARGET) resources

$(TARGET): $(SRC)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $(SRC) $(LDFLAGS)

resources:
	@mkdir -p $(RESOURCES_DST)
	@cp -r $(RESOURCES_SRC)/. $(RESOURCES_DST)/

clean:
	rm -rf bin