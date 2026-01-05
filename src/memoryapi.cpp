#include "memoryapi.h"

  void MemoryMap::map(std::vector<float>* graph) {
      HANDLE handle = CreateFileMappingW(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, sizeof(SharedVector), L"StringFileMap");
      
      if (handle == NULL) {
          std:: cerr << "Create Mapping FAILED: " << GetLastError() << "\n";
      }

      SharedVector* pShared = (SharedVector*) MapViewOfFile(handle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(SharedVector));

      if (!pShared) {
          std::cerr << "MAP FAILED: " << GetLastError() << "\n";
      }

      pShared->ready = 0;
      size_t n = graph->size();
      if (n > 100000) n = 100000;
      pShared->size = n;

      memcpy(pShared->data, graph->data(), n * sizeof(float));

      pShared->ready = 1;

  }

  void MemoryMap::unmap() {
      if (pShared) UnmapViewOfFile(pShared);
      if (handle) CloseHandle(handle);
  }

SharedVector* MemoryMap::get_map() {
    return pShared;
}
