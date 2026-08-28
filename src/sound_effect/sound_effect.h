#ifndef _SOUND_EFFECT_H
#define _SOUND_EFFECT_H

#include <raylib.h>

extern Sound wall_hit_sound;
extern Sound paddle_hit_sound;
extern Sound score_point_sound;
extern Sound endgame_sound;

Sound init_paddle_hit_sound();
Sound init_wall_hit_sound();
Sound init_score_point_sound();
Sound init_endgame_sound();

#endif