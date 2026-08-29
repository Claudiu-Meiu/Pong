#include "score.h"

int rounds = 10;

int score_left_paddle;
int score_right_paddle;

bool endgame = false;

void init_score(void) {
  score_left_paddle = 0;
  score_right_paddle = 0;
}

void update_score(void) {
  if (ball.position.x <= 0) {
    score_right_paddle++;
    PlaySound(score_point_sound);
    init_ball(randomized_ball_speed());
  }
  if (ball.position.x >= GetScreenWidth()) {
    score_left_paddle++;
    PlaySound(score_point_sound);
    init_ball(randomized_ball_speed());
  }
}

void check_score_and_reset(void) {
  if (!endgame &&
      (score_left_paddle == rounds || score_right_paddle == rounds)) {

    endgame = true;

    PlaySound(endgame_sound);
    init_ball(no_ball_speed());
  }

  if (endgame && IsKeyPressed(KEY_ENTER)) {
    endgame = false;

    score_left_paddle = 0;
    score_right_paddle = 0;

    init_paddle();
    init_ball(randomized_ball_speed());
  }
}

void draw_score(void) {
  const int font_size = 100;

  const char *left_score_text = TextFormat("%d", score_left_paddle);
  const int left_score_text_measured = MeasureText(left_score_text, font_size);

  const char *right_score_text = TextFormat("%d", score_right_paddle);
  const int right_score_text_measured =
      MeasureText(right_score_text, font_size);

  DrawText(left_score_text,
           (GetScreenWidth() - left_score_text_measured) / 2.0f - 100.0f, 50,
           font_size, RAYWHITE);

  DrawText(right_score_text,
           (GetScreenWidth() - right_score_text_measured) / 2.0f + 100.0f, 50,
           font_size, RAYWHITE);
}

void draw_endgame(void) {
  const char *winner_text = "You won!";
  const int winner_text_font_size = 50;
  const int winner_text_measured =
      MeasureText(winner_text, winner_text_font_size);

  const char *new_game_text = "Press ENTER to start a new game";
  const int new_game_text_font_size = 25;
  const int new_game_text_measured =
      MeasureText(new_game_text, new_game_text_font_size);

  if (score_left_paddle == rounds) {
    DrawText(winner_text, (GetScreenWidth() - winner_text_measured) / 3.0,
             GetScreenHeight() / 2.0f, winner_text_font_size, RAYWHITE);
  }

  if (score_right_paddle == rounds) {
    DrawText(winner_text, (GetScreenWidth() - winner_text_measured) / 1.5f,
             GetScreenHeight() / 2.0f, winner_text_font_size, RAYWHITE);
  }

  if (score_left_paddle == rounds || score_right_paddle == rounds) {
    DrawText(new_game_text, (GetScreenWidth() - new_game_text_measured) / 2.0f,
             GetScreenHeight() / 1.075f, new_game_text_font_size, RAYWHITE);
  }
}