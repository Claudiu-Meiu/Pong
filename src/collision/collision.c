#include <math.h>
#include <raylib.h>

void check_ball_collision_with_wall(Vector2 *ball_position, float ball_radius,
                                    Vector2 *ball_speed) {
  if ((ball_position->x >= (GetScreenWidth() - ball_radius)) ||
      (ball_position->x <= ball_radius)) {
    ball_speed->x *= -1.0f;
  }
  // For top and bottom
  if (ball_position->y <= ball_radius) {
    ball_position->y = ball_radius;
    ball_speed->y *= -1.0f;
  }
  if (ball_position->y >= GetScreenHeight() - ball_radius) {
    ball_position->y = GetScreenHeight() - ball_radius;
    ball_speed->y *= -1.0f;
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

  // For the right paddle
  if (paddle.x < GetScreenWidth() / 2.0f) {
    ball_position->x = paddle.x + paddle.width + ball_radius;

    if (ball_speed->x < 0) {
      ball_speed->x *= -1.0f;
      ball_speed->y = hit_position * 500.0f;
      ball_speed->x = fabsf(ball_speed->x) + 25.0f;
    }
  }
  // For the right paddle
  if (paddle.x > GetScreenWidth() / 2.0f) {
    ball_position->x = paddle.x - ball_radius;

    if (ball_speed->x > 0) {
      ball_speed->x *= -1.0f;
      ball_speed->y = hit_position * 500.0f;
      ball_speed->x = -(fabsf(ball_speed->x) + 25.0f);
    }
  }
}