#include "../game_screen/entities/gameplay/ball/ball.h"
#include <raylib.h>

int score_left_paddle;
int score_right_paddle;

void init_score() {
  score_left_paddle = 0;
  score_right_paddle = 0;
}

void update_score() {
  if (ball.position.x <= 0) {
    score_right_paddle++;
    init_ball();
  }
  if (ball.position.x >= GetScreenWidth()) {
    score_left_paddle++;
    init_ball();
  }
}

void draw_score() {
  const char *left_score = TextFormat("%d", score_left_paddle);
  const char *right_score = TextFormat("%d", score_right_paddle);

  DrawText(left_score, GetScreenWidth() / 2 - 100, 50, 50, WHITE);
  DrawText(right_score, GetScreenWidth() / 2 + 70, 50, 50, WHITE);
}