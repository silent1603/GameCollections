#include"pch.h"
#include"ball.h"
#include"Paddle.h"
#include"AI.h"
#include"Score.h"

Color Green = Color{38,185,154,255};
Color Dark_Green = Color{20,160,133,255};
Color Light_Green = Color{129,204,154,255};


int main(int argc , char** argv)
{
    
    Ball ball;
    std::cout << "Starting the game" << std::endl;
    int screen_width = 1280;
    int screen_height = 800;
    int fps = 60;

    ball.radius = 20;
    ball.x = screen_width/2;
    ball.y = screen_height/2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    Paddle player;

    player.width = 25;
    player.height = 120;
    player.x = screen_width - player.width - 10;
    player.y = screen_height/2 - player.height /2;
    player.speed = 6;

    AI AI;
    
    AI.paddle.width = 25;
    AI.paddle.height = 120;
    AI.paddle.x = 10;
    AI.paddle.y = screen_height/2 - AI.paddle.height /2;
    AI.paddle.speed = 6;

    Score score;
    score.left_score = score.right_score = 0 ;

    InitWindow(screen_width,screen_height,"PingPong");
    SetTargetFPS(fps);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        //Updating
        ball = UpdateBall(ball);
        score = UpdateScore(ball,score);
        player = UpdatePaddle(player);
        AI = UpdateAI(AI,ball.y);

        //checking for collision
        if(CheckCollisionCircleRec(Vector2{ball.x,ball.y},ball.radius,Rectangle{player.x,player.y,player.width,player.height}))
        {
            ball.speed_x *= -1;
        }

        if(CheckCollisionCircleRec(Vector2{ball.x,ball.y},ball.radius,Rectangle{AI.paddle.x,AI.paddle.y,AI.paddle.width,AI.paddle.height}))
        {
            ball.speed_x *= -1;
        }

        ClearBackground(Dark_Green);
        DrawRectangle(screen_width/2,0,screen_width/2,screen_height,Green);
        DrawCircle(screen_width/2,screen_height/2,150,Light_Green);
        DrawLine(screen_width/2,0,screen_width/2,screen_height,WHITE);
        
        DrawBall(ball);
        DrawAI(AI);
        DrawPaddle(player);
        DrawText(TextFormat("%i",score.left_score),screen_width / 4 -20 , 20, 80,WHITE);
        DrawText(TextFormat("%i",score.right_score),3*screen_width/4 -20 , 20 , 80 ,WHITE);
        
        EndDrawing();
    }
    CloseWindow();
    return 0;
}