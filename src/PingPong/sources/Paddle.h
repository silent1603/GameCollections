#pragma once

struct Paddle
{
    float x , y , width , height;
    int speed;
};

void DrawPaddle(Paddle);
Paddle UpdatePaddle(Paddle paddle);
Paddle LimitMovement(Paddle paddle);