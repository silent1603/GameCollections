#include "pch.h"
#include "Paddle.h"

void DrawPaddle(Paddle paddle)
{
    DrawRectangleRounded(Rectangle{paddle.x  , paddle.y ,paddle.width,paddle.height},0.8,0, WHITE);
}

Paddle UpdatePaddle(Paddle paddle)
{
    if(IsKeyDown(KEY_UP))
    {
        paddle.y = paddle.y - paddle.speed;
    }
    else if(IsKeyDown(KEY_DOWN))
    {
        paddle.y = paddle.y + paddle.speed;
    }

    paddle = LimitMovement(paddle);
    return paddle;
}

Paddle LimitMovement(Paddle paddle)
{
    if(paddle.y <= 0) 
    {
        paddle.y = 0;
    }
    if(paddle.y+ paddle.height >= GetScreenHeight())
    {
        paddle.y = GetScreenHeight() - paddle.height;
    }
    return paddle;
}