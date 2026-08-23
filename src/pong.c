#include "collision/collision.h"
#include "entities/ball/ball.h"
#include "entities/dividing_line/dividing_line.h"
#include "entities/paddle/paddle.h"
#include <raylib.h>

int main(void) {
  const int screen_width = 1920;
  const int screen_height = 1080;

  InitWindow(screen_width, screen_height, "Pong");
  ToggleFullscreen();
  SetTargetFPS(0);

  init_paddle();
  init_dividing_line();
  init_ball();

  // GAME LOOP
  while (!WindowShouldClose()) {
    update_paddle_position_and_speed();
    update_ball_position_based_on_speed();

    // Check collisions
    check_ball_collision_with_wall(&ball.position, ball.radius, &ball_speed);

    check_ball_collision_with_paddle(left_paddle, &ball.position, ball.radius,
                                     &ball_speed);

    check_ball_collision_with_paddle(right_paddle, &ball.position, ball.radius,
                                     &ball_speed);

    // DRAW
    BeginDrawing();

    ClearBackground(BLACK);

    draw_paddle();
    draw_dividing_line();
    draw_ball();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
