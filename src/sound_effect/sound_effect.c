#include <raylib.h>

Sound paddle_hit_sound;
Sound wall_hit_sound;
Sound score_point_sound;
Sound endgame_sound;

Sound init_paddle_hit_sound() {
  return paddle_hit_sound = LoadSound("resources/sounds/paddle_hit.wav");
}
Sound init_wall_hit_sound() {
  return wall_hit_sound = LoadSound("resources/sounds/wall_hit.wav");
}

Sound init_score_point_sound() {
  return score_point_sound = LoadSound("resources/sounds/score_point.wav");
}

Sound init_endgame_sound() {
  return endgame_sound = LoadSound("resources/sounds/endgame.wav");
}