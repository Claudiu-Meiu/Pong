#include <raylib.h>

typedef struct Ball {
  Vector2 position;
  float radius;
} Ball;

Ball ball;

Vector2 ball_speed = {500.0f, 500.0f};

void init_ball() {
  ball = (Ball){{GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f}, 10};
}

void update_ball_position_based_on_speed() {
  ball.position.x += GetFrameTime() * ball_speed.x;
  ball.position.y += GetFrameTime() * ball_speed.y;
}

void draw_ball() { DrawCircleV(ball.position, ball.radius, WHITE); }