#include <cstdio>
#include "raylib.h"

int main()
{
    int width = 350;
    int height = 200;

    //Creating a window using raylib
    InitWindow(width, height, "Axe Game Window");
    
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(RED);
        EndDrawing();
    }
}