#include <math.h>
#include <raylib.h>

typedef struct Ball {
  Vector2 position;
  int radius;
} Ball;

int main(void) {
  // INIT
  const int screen_width = 1920;
  const int screen_height = 1080;

  InitWindow(screen_width, screen_height, "Da Pong");
  ToggleFullscreen();

  Rectangle left_paddle = {300.0f - 10.0f / 2.0f,
                           GetScreenHeight() / 2.0f - 100.0f / 2.0f, 10.0f,
                           100.0f};

  Rectangle right_paddle = {GetScreenWidth() - 300.0f - 10.0f / 2.0f,
                            GetScreenHeight() / 2.0f - 100.0f / 2.0f, 10.0f,
                            100.0f};

  Ball ball = {{GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f}, 10};

  float left_paddle_speed = 1500.0f;
  float right_paddle_speed = 1500.0f;
  Vector2 ball_speed = {500.0f, 500.0f};

  bool ball_collision_with_left_paddle = false;
  bool ball_collision_with_right_paddle = false;

  SetTargetFPS(0);

  // GAME LOOP
  while (!WindowShouldClose()) {
    // UPDATE

    float delta_time = GetFrameTime();

    // Left paddle moving up
    if (IsKeyDown(KEY_W)) {
      if (left_paddle.y <= 0) {
        left_paddle_speed += 0;
      } else {
        left_paddle.y -= delta_time * left_paddle_speed;
      }
    }
    // Left paddle moving down
    if (IsKeyDown(KEY_S)) {
      if (left_paddle.y >= (GetScreenHeight() - left_paddle.height)) {
        left_paddle_speed += 0;
      } else {
        left_paddle.y += delta_time * left_paddle_speed;
      }
    }
    // Right paddle moving up
    if (IsKeyDown(KEY_UP)) {
      if (right_paddle.y <= 0) {
        right_paddle_speed += 0;
      } else {
        right_paddle.y -= delta_time * right_paddle_speed;
      }
    }
    // Right paddle moving down
    if (IsKeyDown(KEY_DOWN)) {
      if (right_paddle.y >= (GetScreenHeight() - right_paddle.height)) {
        right_paddle_speed += 0;
      } else {
        right_paddle.y += delta_time * right_paddle_speed;
      }
    }

    ball.position.x += delta_time * ball_speed.x;
    ball.position.y += delta_time * ball_speed.y;

    // Check collisions
    ball_collision_with_left_paddle =
        CheckCollisionCircleRec(ball.position, ball.radius, left_paddle);
    ball_collision_with_right_paddle =
        CheckCollisionCircleRec(ball.position, ball.radius, right_paddle);

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

    if (ball_collision_with_left_paddle) {
      ball.position.x = (left_paddle.x + left_paddle.width) + ball.radius;
      if (ball_speed.x < 0 ) {
        ball_speed.x *= -1.0f;
        // increase speed (linear progression)
        ball_speed.x = (fabsf(ball_speed.x) + 25.0f);
      }
    }
    if (ball_collision_with_right_paddle) {
      ball.position.x = right_paddle.x - ball.radius;
      if (ball_speed.x > 0) {
        ball_speed.x *= -1.0f;
        // increase speed (linear progression)
        ball_speed.x = -(fabsf(ball_speed.x) + 25.0f);
      }
    }

    // DRAW
    BeginDrawing();

    ClearBackground(BLACK);

    // Left paddle
    DrawRectangle(left_paddle.x, left_paddle.y, left_paddle.width,
                  left_paddle.height, WHITE);
    // Ball
    DrawCircleV(ball.position, ball.radius, WHITE);
    // Right paddle
    DrawRectangle(right_paddle.x, right_paddle.y, right_paddle.width,
                  right_paddle.height, WHITE);

    EndDrawing();
  }

  // DE-INIT
  CloseWindow();

  return 0;
}
