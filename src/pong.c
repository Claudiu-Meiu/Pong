#include "collision/collision.h"
#include "game_screen/entities/gameplay/ball/ball.h"
#include "game_screen/entities/gameplay/dividing_line/dividing_line.h"
#include "game_screen/entities/gameplay/paddle/paddle.h"
#include "game_screen/entities/menu/start_button/start_button.h"
#include "game_screen/game_screen.h"
#include <raylib.h>

int main(void) {
  const int screen_width = 1920;
  const int screen_height = 1080;

  InitWindow(screen_width, screen_height, "Pong");
  ToggleFullscreen();
  SetTargetFPS(0);

  GameScreen current_screen = MENU;

  init_paddle();
  init_dividing_line();
  init_ball();

  // GAME LOOP
  while (!WindowShouldClose()) {
    // UPDATE
    switch (current_screen) {
    case MENU: {
      current_screen = start_button_action(current_screen);
    } break;
    case GAMEPLAY: {
      update_paddle_position_and_speed();
      update_ball_position_based_on_speed();

      // Check collisions
      check_ball_collision_with_wall(ball.position, ball.radius, &ball_speed);

      check_ball_collision_with_paddle(left_paddle, ball.position, ball.radius,
                                       &ball_speed);

      check_ball_collision_with_paddle(right_paddle, ball.position,
                                       ball.radius, &ball_speed);
    } break;
    default:
      break;
    }

    // DRAW
    BeginDrawing();

    ClearBackground(BLACK);

    switch (current_screen) {
    case MENU: {
      draw_start_button();
    } break;
    case GAMEPLAY: {
      draw_paddle();
      draw_dividing_line();
      draw_ball();
    } break;
    default:
      break;
    }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
