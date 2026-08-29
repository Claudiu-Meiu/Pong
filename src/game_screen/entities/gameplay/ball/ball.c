#include "ball.h"

Ball ball;

void init_ball(Vector2 speed) {
  ball = (Ball){.position = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f},
                .radius = 10.0f,
                .speed = speed};
}

void update_ball_position(void) {
  float dt = GetFrameTime();

  ball.position.y += dt * ball.speed.y;
  ball.position.x += dt * ball.speed.x;
}

void draw_ball(void) { DrawCircleV(ball.position, ball.radius, WHITE); }

Vector2 randomized_ball_speed(void) {
  Vector2 speeds[] = {
      {500.0f, 500.0f}, {-500.0f, 500.0f}, {500.0f, 0.0f},
      {-500.0f, 0.0f},  {500.0f, -500.0f}, {-500.0f, -500.0f},
  };
  return speeds[rand() % (sizeof(speeds) / sizeof(speeds[0]))];
}

Vector2 no_ball_speed(void) { return (Vector2){0.0f, 0.0f}; }