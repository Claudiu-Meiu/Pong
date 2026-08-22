#include "ball/ball.h"
#include "collision/collision.h"
#include "paddle/paddle.h"
#include <raylib.h>

int main(void) {
  const int screen_width = 1920;
  const int screen_height = 1080;

  InitWindow(screen_width, screen_height, "Pong");
  ToggleFullscreen();
  SetTargetFPS(0);

  init_paddle();
  init_ball();

  // GAME LOOP
  while (!WindowShouldClose()) {
    update_paddle_position_and_speed();
    update_ball_position_based_on_speed();

    // Check collisions
    check_ball_collision_with_wall();
    check_ball_collision_with_paddle();

    // DRAW
    BeginDrawing();

    ClearBackground(BLACK);

    draw_paddle();
    draw_ball();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
