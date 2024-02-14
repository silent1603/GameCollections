#pragma once
#include "Ball.h"
struct Score
{
    int left_score,right_score;
};

Score UpdateScore(Ball& ball,Score score);