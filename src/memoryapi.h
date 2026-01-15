#ifdef _WIN32
#include "windows.h"
#endif

#include "cstddef"
#include "shared_vector.h"
class MemoryMap {
public:

    void map(std::vector<float>* graph);
    void unmap();
    SharedVector* get_map();
};
