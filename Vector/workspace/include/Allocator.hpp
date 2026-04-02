#pragma once

namespace mds {

  template<class T>
  struct Allocator {
   public:
    using value_type = T;

    T* allocate(size_t n);
    void deallocate(T* pSpace, size_t n);
  };

}

template<class T>
T* mds::Allocator<T>::allocate(size_t n) {
  T* pSpace = static_cast<T*>(std::malloc(n * sizeof(T)));

  if (!pSpace) {
    throw std::bad_alloc();
  }
  
  return pSpace;
}

template<class T>
void mds::Allocator<T>::deallocate(T* pSpace, size_t n) {
  free(pSpace);
}