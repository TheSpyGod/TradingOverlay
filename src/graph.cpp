#include "graph.h"

void Graph::initVector() {
    SharedVector* shared = m.get_map();
    
    graph.assign(shared->data, shared->data + shared->size);

}


