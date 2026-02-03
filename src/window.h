#include <raylib.h>
#include "graph.h"
#include "draw.h"
#include <cstdlib>

class Window {
public:
    Graph g;
    Draw d;
    Vector2 getDifferencePosition(bool& isFirstDrag);
    Vector2 getOriginalDragPosition(bool& isFirstDrag);
    void calculateMovement(int& savedX, int& savedY, bool& isFirstDrag);
    void init();
};
