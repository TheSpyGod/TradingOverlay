#include <vector>
#include <iostream>
#include <raylib.h>
#include <algorithm>
class Draw {
private:
    std::vector<int> vp;
    int movementY = 0;
    int movementX = 0;

public:
    void drawConnections(const std::vector<int>& data);
    void moveGraph(int valueX, int valueY);
    void getViewpoint(const std::vector<int>& data);
};
