#include <cstdio>
#include "raylib.h"

int main()
{
    // Window dimension
    int width = 350;
    int height = 200;

    //Using Braced Initialization
    bool checker{false};

    //Circle Coordinates
    int circle_x{175};
    int circle_y{100};

    //Creating a window using raylib
    InitWindow(width, height, "Axe Game Window");
    
    SetTargetFPS(60);
    while (WindowShouldClose() == checker)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        DrawCircle(circle_x, circle_y, 25, BLUE);

        if (IsKeyDown(KEY_D))
        {
            circle_x = circle_x + 10;
        }
        else if (IsKeyDown(KEY_A))
        {
            circle_y = circle_y - 10;
        }
        

        EndDrawing();
    }
}