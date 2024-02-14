#include "pch.h"
#include "AI.h"

void DrawAI(AI ai)
{
    DrawPaddle(ai.paddle);
}

AI UpdateAI(AI ai,float ball_y)
{
    if(ai.paddle.y + ai.paddle.height/2 > ball_y)
    {
        ai.paddle.y = ai.paddle.y - ai.paddle.speed;
    }
    if(ai.paddle.y + ai.paddle.height/2 <= ball_y)
    {
        ai.paddle.y = ai.paddle.y + ai.paddle.speed;
    }
    ai.paddle = LimitMovement(ai.paddle);
    return ai;
}