#pragma once
#include "Paddle.h"
struct AI
{
    Paddle paddle;
};

void DrawAI(AI ai);
AI UpdateAI(AI ai,float ball_y);

