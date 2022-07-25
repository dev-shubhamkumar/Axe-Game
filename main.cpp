#include <cstdio>
#include "raylib.h"

int main()
{
    int width = 350;
    int height = 200;

    //Using Braced Initialization
    bool checker{false};

    //Creating a window using raylib
    InitWindow(width, height, "Axe Game Window");
    
    while (WindowShouldClose() == checker)
    {
        BeginDrawing();
        ClearBackground(RED);
        EndDrawing();
    }
}