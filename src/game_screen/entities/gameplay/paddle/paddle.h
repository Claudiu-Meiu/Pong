#ifndef PADDLE_H
#define PADDLE_H

#include <raylib.h>

extern Rectangle left_paddle;
extern Rectangle right_paddle;

extern float left_paddle_speed;
extern float right_paddle_speed;

void init_paddle(void);
void update_paddle_position(void);
void draw_paddle(void);

#endif