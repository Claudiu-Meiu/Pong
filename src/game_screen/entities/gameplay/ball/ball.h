#ifndef _BALL_H
#define _BALL_H

#include <raylib.h>

typedef struct Ball {
  Vector2 position;
  float radius;
} Ball;

extern Ball ball;
extern Vector2 speeds[6];
extern Vector2 random_speed;
extern Vector2 ball_speed;

void init_ball();
void update_ball_position_based_on_speed();
void draw_ball();

#endif