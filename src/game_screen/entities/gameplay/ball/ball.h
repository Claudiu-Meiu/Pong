#ifndef _BALL_H
#define _BALL_H

#include <raylib.h>

typedef struct Ball {
  Vector2 position;
  float radius;
} Ball;

extern Ball ball;
extern Vector2 current_ball_speed;

void init_ball(Vector2 speed);
void update_ball_position();
void draw_ball();
Vector2 randomized_ball_speed();
Vector2 no_ball_speed();

#endif