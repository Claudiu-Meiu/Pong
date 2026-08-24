CC = gcc

CFLAGS = -Wall -Wextra -I./src
LDFLAGS = -lraylib -lm

TARGET = bin/pong

SRC = \
	src/pong.c \
	src/collision/collision.c \
	src/game_screen/entities/gameplay/ball/ball.c \
	src/game_screen/entities/gameplay/dividing_line/dividing_line.c \
	src/game_screen/entities/gameplay/paddle/paddle.c \
	src/game_screen/entities/menu/start_button/start_button.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p bin
	$(CC) $(CFLAGS) -o $@ $(SRC) $(LDFLAGS)

clean:
	rm -f $(TARGET)