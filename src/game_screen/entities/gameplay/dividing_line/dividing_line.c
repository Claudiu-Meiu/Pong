#include "dividing_line.h"

Vector2 dividing_line_start;
Vector2 dividing_line_end;

void init_dividing_line(void) {
  dividing_line_start = (Vector2){GetScreenWidth() / 2.0f, 0.0f};
  dividing_line_end = (Vector2){GetScreenWidth() / 2.0f, GetScreenHeight()};
}

void draw_dividing_line(void) {
  DrawLineEx(dividing_line_start, dividing_line_end, 2.0f, DARKGRAY);
}