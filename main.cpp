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
    int circle_x{width/2 - 200};
    int circle_y{height/2};
    int circle_radius{25};
    int circle_radius_inner{20};
    //Circle Edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    //Rectangle Coordinates
    int axe_x{400};
    int axe_y{0};
    int axe_length(50);
    //Rectangle Edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};

    int direction{10};

    //Logic for collision
    bool collision_with_axe =   (b_axe_y >= u_circle_y) && 
                                (u_axe_y <= b_circle_y) && 
                                (l_axe_x <= r_circle_x) && 
                                (r_axe_x >= l_circle_x);

    //Creating a window using raylib
    InitWindow(width, height, "Axe Game Window");
    
    SetTargetFPS(60);
    while (WindowShouldClose() == checker)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (collision_with_axe)
        {
            DrawText("Game Over", 400, 200, 40, RED);
        }
        else 
        {
            //Game Logic Begins

            //Updating Edges at every step
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            collision_with_axe =    (b_axe_y >= u_circle_y) && 
                                    (u_axe_y <= b_circle_y) && 
                                    (l_axe_x <= r_circle_x) && 
                                    (r_axe_x >= l_circle_x);

            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            DrawCircle(circle_x, circle_y, circle_radius_inner, WHITE);

            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);
            axe_y += direction;
            if(axe_y > height || axe_y < 0)
            {
                direction = -direction;
            }

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

            //Game Logic Ends
        }
        EndDrawing();
    }
}