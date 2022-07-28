#include <cstdio>
#include "raylib.h"

int main()
{
    // Window dimension
    int width = 800;
    int height = 450;

    //Using Braced Initialization
    bool checker{false};

    //Circle Coordinates
    int circle_x{width/2};
    int circle_y{height/2};

    //Rectangle Coordinates
    int axe_x{400};
    int axe_y{0};

    //Creating a window using raylib
    InitWindow(width, height, "Axe Game Window");
    
    SetTargetFPS(60);
    while (WindowShouldClose() == checker)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        DrawCircle(circle_x, circle_y, 25, BLUE);
        DrawCircle(circle_x, circle_y, 20, WHITE);

        DrawRectangle(axe_x, axe_y, 50, 50, RED);
        axe_y += 10;

        if (IsKeyDown(KEY_D) && circle_x < width)
        {
            circle_x = circle_x + 10;
        }
        else if (IsKeyDown(KEY_A) && circle_x > 0)
        {
            circle_x = circle_x - 10;
        }
        else if (IsKeyDown(KEY_W) && circle_y > 0)
        {
            circle_y = circle_y - 10;
        }
        else if (IsKeyDown(KEY_X) && circle_y < height)
        {
            circle_y = circle_y + 10;
        }

        EndDrawing();
    }
}