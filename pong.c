#include <raylib.h>

typedef struct Ball {
  Vector2 position;
  int radius;
} Ball;

int main(void) {
  // Init
  const int screenWidth = 1920;
  const int screenHeight = 1080;

  InitWindow(screenWidth, screenHeight, "Da Pong");
  ToggleFullscreen();

  Rectangle leftPaddle = {300.0f - 10.0f / 2.0f,
                          GetScreenHeight() / 2.0f - 100.0f / 2.0f, 10.0f,
                          100.0f};

  Rectangle rightPaddle = {GetScreenWidth() - 300.0f - 10.0f / 2.0f,
                           GetScreenHeight() / 2.0f - 100.0f / 2.0f, 10.0f,
                           100.0f};

  Ball ball = {{GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f}, 10};

  float leftPaddleSpeed = 1500.0f;
  float rightPaddleSpeed = 1500.0f;
  Vector2 ballSpeed = {1000.0f, 500.0f};

  bool ballCollisionWithLeftPaddle = false;
  bool ballCollisionWithRightPaddle = false;

  SetTargetFPS(0);

  // Game loop
  while (!WindowShouldClose()) {
    // Update
    if (IsKeyDown(KEY_W)) { // Left paddle moving up
      if (leftPaddle.y <= 0) {
        leftPaddleSpeed += 0;
      } else {
        leftPaddle.y -= GetFrameTime() * leftPaddleSpeed;
      }
    }
    if (IsKeyDown(KEY_S)) { // Left paddle moving down
      if (leftPaddle.y >= (GetScreenHeight() - leftPaddle.height)) {
        leftPaddleSpeed += 0;
      } else {
        leftPaddle.y += GetFrameTime() * leftPaddleSpeed;
      }
    }

    if (IsKeyDown(KEY_UP)) { // Right paddle moving up
      if (rightPaddle.y <= 0) {
        rightPaddleSpeed += 0;
      } else {
        rightPaddle.y -= GetFrameTime() * rightPaddleSpeed;
      }
    }
    if (IsKeyDown(KEY_DOWN)) { // Right paddle moving down
      if (rightPaddle.y >= (GetScreenHeight() - rightPaddle.height)) {
        rightPaddleSpeed += 0;
      } else {
        rightPaddle.y += GetFrameTime() * rightPaddleSpeed;
      }
    }

    ball.position.x += GetFrameTime() * ballSpeed.x;
    ball.position.y += GetFrameTime() * ballSpeed.y;

    ballCollisionWithLeftPaddle =
        CheckCollisionCircleRec(ball.position, ball.radius, leftPaddle);
    ballCollisionWithRightPaddle =
        CheckCollisionCircleRec(ball.position, ball.radius, rightPaddle);

    // Check collisions
    if ((ball.position.x >= (GetScreenWidth() - ball.radius)) ||
        (ball.position.x <= ball.radius))
      ballSpeed.x *= -1.0f;
    if ((ball.position.y >= (GetScreenHeight() - ball.radius)) ||
        (ball.position.y <= ball.radius))
      ballSpeed.y *= -1.0f;

    if (ballCollisionWithLeftPaddle || ballCollisionWithRightPaddle) {
      ballSpeed.x *= -1.0f;
      ballSpeed.y *= -1.0f;
    }

    // Draw
    BeginDrawing();

    ClearBackground(BLACK);

    // Left paddle
    DrawRectangle(leftPaddle.x, leftPaddle.y, leftPaddle.width,
                  leftPaddle.height, WHITE);
    // Ball
    DrawCircleV(ball.position, ball.radius, WHITE);
    // Right paddle
    DrawRectangle(rightPaddle.x, rightPaddle.y, rightPaddle.width,
                  rightPaddle.height, WHITE);

    EndDrawing();
  }

  // De-init
  CloseWindow();

  return 0;
}
