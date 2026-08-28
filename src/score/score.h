#ifndef _SCORE_H
#define _SCORE_H

extern int rounds;
extern int score_left_paddle;
extern int score_right_paddle;
extern bool endgame;

void init_score();
void update_score();
void check_score_and_reset();
void draw_score();
void draw_endgame();

#endif