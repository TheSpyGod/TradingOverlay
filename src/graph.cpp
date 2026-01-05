#include "graph.hpp"

void Graph::initVector(std::vector<float> g) {
    SharedVector* shared = m.get_map();
    
    graph.assign(shared->data, shared->data + shared->size);

}

