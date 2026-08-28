#ifndef _PADDLE_H
#define _PADDLE_H

#include <raylib.h>

extern Rectangle left_paddle;
extern Rectangle right_paddle;

extern float left_paddle_speed;
extern float right_paddle_speed;

void init_paddle();
void update_paddle_position();
void draw_paddle();

#endif