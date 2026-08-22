#include "../ball/ball.h"
#include "../paddle/paddle.h"
#include <math.h>

void check_ball_collision_with_wall() {
  if ((ball.position.x >= (GetScreenWidth() - ball.radius)) ||
      (ball.position.x <= ball.radius)) {
    ball_speed.x *= -1.0f;
  }

  if (ball.position.y <= ball.radius) {
    ball.position.y = ball.radius;
    ball_speed.y *= -1.0f;
  }
  if (ball.position.y >= GetScreenHeight() - ball.radius) {
    ball.position.y = GetScreenHeight() - ball.radius;
    ball_speed.y *= -1.0f;
  }
}

void check_ball_collision_with_paddle() {
  bool ball_collision_with_left_paddle =
      CheckCollisionCircleRec(ball.position, ball.radius, left_paddle);
  bool ball_collision_with_right_paddle =
      CheckCollisionCircleRec(ball.position, ball.radius, right_paddle);

  if (ball_collision_with_left_paddle) {
    ball.position.x = (left_paddle.x + left_paddle.width) + ball.radius;

    // Check ball hit vertically on the left paddle
    float paddle_center_y = left_paddle.y + left_paddle.height / 2.0f;
    float hit_offset = ball.position.y - paddle_center_y;
    float hit_position = hit_offset / (left_paddle.height / 2.0f);

    if (ball_speed.x < 0) {
      ball_speed.x *= -1.0f;
      ball_speed.y = hit_position * 500.0f;
      // increase speed (linear progrssion)
      ball_speed.x = fabsf(ball_speed.x) + 25.0f;
    }
  }
  if (ball_collision_with_right_paddle) {
    ball.position.x = right_paddle.x - ball.radius;

    // Check ball hit vertically on the right paddle
    float paddle_center_y = right_paddle.y + right_paddle.height / 2.0f;
    float hit_offset = ball.position.y - paddle_center_y;
    float hit_position = hit_offset / (right_paddle.height / 2.0f);

    if (ball_speed.x > 0) {
      ball_speed.x *= -1.0f;
      ball_speed.y = hit_position * 500.0f;
      // increase speed (linear progrssion)
      ball_speed.x = -(fabsf(ball_speed.x) + 25.0f);
    }
  }
}