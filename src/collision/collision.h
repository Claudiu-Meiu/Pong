#ifndef _COLLISION_H
#define _COLLISION_H

#include <raylib.h>

void check_ball_collision_with_wall(Vector2 *ball_position, float ball_radius,
                                    Vector2 *ball_speed);

void check_ball_collision_with_paddle(Rectangle paddle, Vector2 *ball_position,
                                      float ball_radius, Vector2 *ball_speed);

void check_paddle_collision_with_wall(float *paddle_position_y,
                                      float paddle_height);

#endif