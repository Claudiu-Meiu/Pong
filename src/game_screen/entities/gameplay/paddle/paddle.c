#include <raylib.h>

Rectangle left_paddle;
Rectangle right_paddle;

float left_paddle_speed = 1500.0f;
float right_paddle_speed = 1500.0f;

void init_paddle() {
  left_paddle =
      (Rectangle){100.0f - 10.0f / 2.0f,
                  GetScreenHeight() / 2.0f - 100.0f / 2.0f, 20.0f, 100.0f};
  right_paddle =
      (Rectangle){GetScreenWidth() - 100.0f - 10.0f / 2.0f,
                  GetScreenHeight() / 2.0f - 100.0f / 2.0f, 20.0f, 100.0f};
};

void update_paddle_position_and_speed() {
  // Left paddle moving up
  if (IsKeyDown(KEY_W)) {
    if (left_paddle.y <= 0) {
      left_paddle_speed += 0;
    } else {
      left_paddle.y -= GetFrameTime() * left_paddle_speed;
    }
  }
  // Left paddle moving down
  if (IsKeyDown(KEY_S)) {
    if (left_paddle.y >= (GetScreenHeight() - left_paddle.height)) {
      left_paddle_speed += 0;
    } else {
      left_paddle.y += GetFrameTime() * left_paddle_speed;
    }
  }

  // Right paddle moving up
  if (IsKeyDown(KEY_UP)) {
    if (right_paddle.y <= 0) {
      right_paddle_speed += 0;
    } else {
      right_paddle.y -= GetFrameTime() * right_paddle_speed;
    }
  }
  // Right paddle moving down
  if (IsKeyDown(KEY_DOWN)) {
    if (right_paddle.y >= (GetScreenHeight() - right_paddle.height)) {
      right_paddle_speed += 0;
    } else {
      right_paddle.y += GetFrameTime() * right_paddle_speed;
    }
  }
}

void draw_paddle() {
  DrawRectangle(left_paddle.x, left_paddle.y, left_paddle.width,
                left_paddle.height, WHITE);

  DrawRectangle(right_paddle.x, right_paddle.y, right_paddle.width,
                right_paddle.height, WHITE);
};