#ifndef _COLLISION_H
#define _COLLISION_H

#include <raylib.h>

void check_ball_collision_with_wall(Vector2 *ball_position, int ball_radius,
                                    Vector2 *ball_speed);

void check_ball_collision_with_paddle(Rectangle paddle, Vector2 *ball_position,
                                      int ball_radius, Vector2 *ball_speed);

#endif