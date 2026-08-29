#ifndef COLLISION_H
#define COLLISION_H

#include "../sound_effect/sound_effect.h"
#include <math.h>
#include <raylib.h>

void check_ball_collision_with_wall(Vector2 *ball_position, float ball_radius,
                                    Vector2 *ball_speed);

void check_ball_collision_with_paddle(Rectangle paddle, Vector2 *ball_position,
                                      float ball_radius, Vector2 *ball_speed);

void check_paddle_collision_with_wall(float *paddle_position_y,
                                      float paddle_height);

#endif