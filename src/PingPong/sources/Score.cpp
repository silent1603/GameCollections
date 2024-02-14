#include "pch.h"
#include "Score.h"
#include "Ball.h"
Score UpdateScore(Ball& ball,Score score)
{
    if(ball.x +  ball.radius >= GetScreenWidth())
    {
        score.left_score++;
        ball = ResetBall(ball);
    }

    if( ball.x - ball.radius <= 0)
    {
        score.right_score++;
        ball = ResetBall(ball);
    }

    return score;
}