#pragma once
#include <cstddef>

class SharedVector {
    volatile int ready;
    size_t size;
    float data[100000];
};
