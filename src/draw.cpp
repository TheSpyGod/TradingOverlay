#include "draw.h"

void Draw::drawConnections(const std::vector<int>& data) {
    getViewpoint(data);

    if (vp.empty()) return;

    int x = 0;
    int lastx = 0;
    int lasty = 500 - vp[0];

    for (size_t i = 1; i < vp.size(); ++i) {
        x += 5;
        int y = 500 - vp[i];
        DrawLine(lastx, lasty, x, y, BLUE);
        lastx = x;
        lasty = y;
    }
}



void Draw::moveGraph(int valueX, int valueY) {
        int calcX = valueX / 5;
        int calcY = valueY / 5;

        if (calcX > 160 || calcY > 100)
        return;

        if (movementY + calcY > 0)
            movementY += calcY;
        else movementY = 0;

        if (movementX + calcX > 0)
            movementX += calcX;
        else movementX = 0;
}

void Draw::getViewpoint(const std::vector<int>& data) {
    vp.clear();
    for (int i = 0; i < 160; i++) {
        if (movementX + i < data.size() && movementX + i - movementY > 0) {
            vp.push_back(data[movementX + i - movementY]);
        }
    }
}

