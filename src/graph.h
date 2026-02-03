#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class Graph {
public:
    std::vector<int> data;

    void readData();
    void formatData();

    const std::vector<int>& getOriginalGraph() const;
};
