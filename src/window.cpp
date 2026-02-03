#include "window.h"

Vector2 Window::getOriginalDragPosition(bool& isFirstDrag) {
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && isFirstDrag) {
        isFirstDrag = false;
        return GetMousePosition();
    } else return {-1,-1};
}

Vector2 Window::getDifferencePosition(bool& isFirstDrag) {
    if (IsMouseButtonUp(MOUSE_LEFT_BUTTON) && !isFirstDrag) {
        isFirstDrag = true;
        return GetMousePosition();
    } else return {-1,-1};
}

void Window::calculateMovement(int& savedX, int& savedY, bool& isFirstDrag) {
 
    Vector2 originalPosition = {-1,-1};
    Vector2 differencePosition = {-1,-1};
    int differenceX = 0;
    int differenceY = 0;

    originalPosition = getOriginalDragPosition(isFirstDrag);
    
    if (originalPosition.x != -1) {
        savedX = originalPosition.x;
        savedY = originalPosition.y;
    }

    differencePosition = getDifferencePosition(isFirstDrag);

    differenceX = savedX - differencePosition.x;
    differenceY = -(savedY - differencePosition.y);

    if (differencePosition.x != -1) {
        d.moveGraph(differenceX, differenceY);
    }

}

void Window::init() {

    const int screenWidth = 800;
    const int screenHeight = 500;
    
    InitWindow(screenWidth, screenHeight, "some title");

    g.readData();
  
    int savedX = -1;
    int savedY = -1;
    bool isFirstDrag = true;

    while (!WindowShouldClose()) {
        BeginDrawing();
        
        ClearBackground(RAYWHITE);

        d.drawConnections(g.getOriginalGraph());
        
        calculateMovement(savedX, savedY, isFirstDrag);

        EndDrawing();
    }

    CloseWindow();
}
