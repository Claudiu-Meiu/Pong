#include "start_button.h"

GameScreen start_button_action(GameScreen current_screen) {
  if (IsKeyPressed(KEY_ENTER)) {
    current_screen = GAMEPLAY;
  }
  return current_screen;
}

void draw_start_button(void) {
  const char *text = "Press ENTER to start the game";
  const int font_size = 60;
  const int text_width = MeasureText(text, font_size);
  DrawText(text, (GetScreenWidth() - text_width) / 2.0f,
           GetScreenHeight() / 2.0f, font_size, RAYWHITE);
}