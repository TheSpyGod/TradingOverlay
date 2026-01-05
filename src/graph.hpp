#include <vector>
#include "./memoryapi.h"
class Graph {
    private:
        std::vector<float> graph;
        MemoryMap m;
    public:
        void initVector(std::vector<float>* g);

};
