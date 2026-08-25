#include <raylib.h>
#include <stdlib.h>

typedef struct Ball {
  Vector2 position;
  float radius;
} Ball;

Ball ball;
Vector2 current_ball_speed;

void init_ball(Vector2 speed) {
  ball = (Ball){{GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f}, 10.0f};
  current_ball_speed = speed;
}

void update_ball_position_based_on_speed() {
  ball.position.x += GetFrameTime() * current_ball_speed.x;
  ball.position.y += GetFrameTime() * current_ball_speed.y;
}

void draw_ball() { DrawCircleV(ball.position, ball.radius, WHITE); }

Vector2 randomized_ball_speed() {
  Vector2 speeds[6] = {
      {500.0f, 500.0f}, {-500.0f, 500.0f}, {500.0f, 0.0f},
      {-500.0f, 0.0f},  {500.0f, -500.0f}, {-500.0f, -500.0f},
  };
  return speeds[rand() % 6];
}

Vector2 no_ball_speed() { return (Vector2){0.0f, 0.0f}; }