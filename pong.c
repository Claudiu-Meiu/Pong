#include <raylib.h>

typedef struct Paddle {
  Vector2 size;
  Vector2 position;
} Paddle;

typedef struct Ball {
  float radius;
  Vector2 position;
} Ball;

int main(void) {
  // Initkr
  SetTargetFPS(0);

  const int screenWidth = 1920;
  const int screenHeight = 1080;

  InitWindow(screenWidth, screenHeight, "Da Pong");
  ToggleFullscreen();

  Paddle leftPaddle = {{10.0f, 100.0f},
                       {300.0f - leftPaddle.size.x / 2.0f,
                        GetScreenHeight() / 2.0f - leftPaddle.size.y / 2.0f}};

  Paddle rightPaddle = {{10.0f, 100.0f},
                        {GetScreenWidth() - 300.0f - rightPaddle.size.x / 2.0f,
                         GetScreenHeight() / 2.0f - rightPaddle.size.y / 2.0f}};

  Ball ball = {10.0f, {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f}};

  float speed = 10.0f;
  const float multiplier = 150.0f * speed;

  // Game loop
  while (!WindowShouldClose()) {
    // Update input
    if (IsKeyDown(KEY_W)) { // Left paddle moving up
      if (leftPaddle.position.y <= 0) {
        speed = 0;
      } else {
        leftPaddle.position.y -= GetFrameTime() * multiplier;
      }
    }
    if (IsKeyDown(KEY_S)) { // Left paddle moving down
      if ((leftPaddle.position.y + leftPaddle.size.y) >= GetScreenHeight()) {
        speed = 0;
      } else {
        leftPaddle.position.y += GetFrameTime() * multiplier;
      }
    }

    if (IsKeyDown(KEY_UP)) { // Right paddle moving up
      if (rightPaddle.position.y <= 0) {
        speed = 0;
      } else {
        rightPaddle.position.y -= GetFrameTime() * multiplier;
      }
    }
    if (IsKeyDown(KEY_DOWN)) { // Right paddle moving down
      if ((rightPaddle.position.y + rightPaddle.size.y) >= GetScreenHeight()) {
        speed = 0;
      } else {
        rightPaddle.position.y += GetFrameTime() * multiplier;
      }
    }

    // Draw
    BeginDrawing();

    ClearBackground(BLACK);

    // Left paddle
    DrawRectangleV(leftPaddle.position, leftPaddle.size, WHITE);

    // Ball
    DrawCircleV(ball.position, ball.radius, WHITE);

    // Right paddle
    DrawRectangleV(rightPaddle.position, rightPaddle.size, WHITE);

    EndDrawing();
  }

  // De-init
  CloseWindow();

  return 0;
}
