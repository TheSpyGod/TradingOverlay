#include "windows.h"
#include "cstddef"
#include "shared_vector.h"
class MemoryMap {
public:

    void map(std::vector<float>* graph);
    void unmap();
    SharedVector* get_map();
};
