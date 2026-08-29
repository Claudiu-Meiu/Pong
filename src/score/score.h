#ifndef SCORE_H
#define SCORE_H

#include "../game_screen/entities/gameplay/ball/ball.h"
#include "../game_screen/entities/gameplay/paddle/paddle.h"
#include "../sound_effect/sound_effect.h"
#include <raylib.h>

extern int rounds;
extern int score_left_paddle;
extern int score_right_paddle;
extern bool endgame;

void init_score(void);
void update_score(void);
void check_score_and_reset(void);
void draw_score(void);
void draw_endgame(void);

#endif