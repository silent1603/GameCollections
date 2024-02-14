#pragma once
struct Ball{
    float x , y;
    float speed_x,speed_y;
    int radius;
};

void DrawBall(Ball ball);
Ball UpdateBall(Ball ball);
Ball ResetBall(Ball ball);