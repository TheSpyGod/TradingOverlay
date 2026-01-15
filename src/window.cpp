#include "window.h"
void Window::init() {
    InitWindow(800,800,"Title");
    int x = 0;
    int y = 1;
    while (!WindowShouldClose())
    {

    //Go through the vector of the points.
    //Draw points on window.
    //Connect points.
    //EndDrawing();
    //Repeat
        BeginDrawing();
        ClearBackground(RAYWHITE);
        initVector();
        if (g.graph[y] > 0 && g.graph[y] < 800 && x < 800 && x > 0) {
            DrawLine(x,x+5,g.graph[y-1],g.graph[y],BLUE);
            if (y < g.graph.size()) {
                x+=10;
                y+=1;
            }
        }
        // If it hits the edge of the window we can do two things
        // Either assign a button to move the area further, reset window to white and start from zero in variables
        // Or Somehow using mouse movement move the graph based on that, make the variables accordingly
        EndDrawing();
    }

    CloseWindow();
}
