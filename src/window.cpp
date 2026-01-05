#include "window.hpp"
void Window::init() {
    InitWindow(800,800,"Title");
    while (!WindowShouldClose())
    {

    //Go through the vector of the points.
    //Draw points on window.
    //Connect points.
    //EndDrawing();
    //Repeat
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
}
