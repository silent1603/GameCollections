#include "pch.h"
#include "Ball.h"
#include "utils.h"

Color Yellow = Color{243,213,91,255};
void DrawBall(Ball ball)
{
    DrawCircle(ball.x,ball.y,ball.radius,Yellow);
}

Ball UpdateBall(Ball ball)
{
    ball.x += ball.speed_x;
    ball.y += ball.speed_y;

    if(ball.y + ball.radius >= GetScreenHeight() || ball.y - ball.radius <= 0)
    {
        ball.speed_y *= -1;
    }
    return ball;
}

Ball ResetBall(Ball ball)
{
    ball.x = GetScreenWidth() / 2;
    ball.y = GetScreenHeight() / 2;
    int speed_choices[2] = { -1,1};
    ball.speed_x *= speed_choices[GetRandomValue(0,1)];
    ball.speed_y *= speed_choices[GetRandomValue(0,1)];
    return ball;
}