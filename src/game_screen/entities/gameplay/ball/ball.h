#ifndef BALL_H
#define BALL_H

#include <raylib.h>
#include <stdlib.h>

typedef struct Ball {
  Vector2 position;
  float radius;
  Vector2 speed;
} Ball;

extern Ball ball;

void init_ball(Vector2 speed);
void update_ball_position(void);
void draw_ball(void);
Vector2 randomized_ball_speed(void);
Vector2 no_ball_speed(void);

#endif