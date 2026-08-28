#include "../sound_effect/sound_effect.h"
#include <math.h>
#include <raylib.h>

void check_ball_collision_with_wall(Vector2 *ball_position, float ball_radius,
                                    Vector2 *ball_speed) {
  // Top wall
  if (ball_position->y <= ball_radius) {
    ball_position->y = ball_radius;
    ball_speed->y *= -1.0f;
    PlaySound(wall_hit_sound);
  }
  // Bottom wall
  if (ball_position->y >= GetScreenHeight() - ball_radius) {
    ball_position->y = GetScreenHeight() - ball_radius;
    ball_speed->y *= -1.0f;
    PlaySound(wall_hit_sound);
  }
}

void check_ball_collision_with_paddle(Rectangle paddle, Vector2 *ball_position,
                                      float ball_radius, Vector2 *ball_speed) {

  bool ball_collision_with_paddle =
      CheckCollisionCircleRec(*ball_position, ball_radius, paddle);

  if (!ball_collision_with_paddle)
    return;

  // Check ball hit vertically on the paddle
  float paddle_center_y = paddle.y + paddle.height / 2.0f;
  float hit_offset = ball_position->y - paddle_center_y;
  float hit_position = hit_offset / (paddle.height / 2.0f);

  // For the left paddle
  if (paddle.x < GetScreenWidth() / 2.0f) {
    ball_position->x = paddle.x + paddle.width + ball_radius;

    if (ball_speed->x < 0) {
      ball_speed->x *= -1.0f;
      ball_speed->y = hit_position * 500.0f;
      ball_speed->x = fabsf(ball_speed->x) + 25.0f;
      PlaySound(paddle_hit_sound);
    }
  }
  // For the right paddle
  if (paddle.x > GetScreenWidth() / 2.0f) {
    ball_position->x = paddle.x - ball_radius;

    if (ball_speed->x > 0) {
      ball_speed->x *= -1.0f;
      ball_speed->y = hit_position * 500.0f;
      ball_speed->x = -(fabsf(ball_speed->x) + 25.0f);
      PlaySound(paddle_hit_sound);
    }
  }
}

void check_paddle_collision_with_wall(float *paddle_position_y,
                                      float paddle_height) {
  if (*paddle_position_y < 0)
    *paddle_position_y = 0;

  if (*paddle_position_y + paddle_height > GetScreenHeight())
    *paddle_position_y = GetScreenHeight() - paddle_height;
}