#include "collision/collision.h"
#include "game_screen/entities/gameplay/ball/ball.h"
#include "game_screen/entities/gameplay/dividing_line/dividing_line.h"
#include "game_screen/entities/gameplay/paddle/paddle.h"
#include "game_screen/entities/menu/start_button/start_button.h"
#include "game_screen/game_screen.h"
#include "score/score.h"
#include "sound_effect/sound_effect.h"
#include <raylib.h>

int main(void) {
  const int screen_width = 1920;
  const int screen_height = 1080;

  InitWindow(screen_width, screen_height, "Pong");
  ToggleFullscreen();
  DisableCursor();
  SetTargetFPS(300);

  GameScreen current_screen = MENU;

  init_paddle();
  init_dividing_line();
  init_ball(randomized_ball_speed());
  init_score();

  InitAudioDevice();
  init_paddle_hit_sound();
  init_wall_hit_sound();
  init_score_point_sound();
  init_endgame_sound();

  // GAME LOOP
  while (!WindowShouldClose()) {
    // UPDATE
    switch (current_screen) {
    case MENU: {
      current_screen = start_button_action(current_screen);
    } break;
    case GAMEPLAY: {
      update_paddle_position();
      update_ball_position();
      update_score();
      check_score_and_reset();

      // Check collisions
      check_ball_collision_with_wall(&ball.position, ball.radius,
                                     &current_ball_speed);

      check_ball_collision_with_paddle(left_paddle, &ball.position, ball.radius,
                                       &current_ball_speed);

      check_ball_collision_with_paddle(right_paddle, &ball.position,
                                       ball.radius, &current_ball_speed);

      check_paddle_collision_with_wall(&left_paddle.y, left_paddle.height);
      check_paddle_collision_with_wall(&right_paddle.y, right_paddle.height);

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
      draw_score();
      draw_endgame();
    } break;
    default:
      break;
    }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
