#pragma once
#include <Allocator.hpp>

namespace mds {
  
  template<class T, class Allocator = mds::Allocator<T>>
  class Vector {
   private:
    Allocator alloc_;

    T* pVector_;
    size_t size_;
    size_t capacity_;

   public:
    Vector();
    Vector(size_t length);
    Vector(size_t length, const T& value);
    Vector(const Vector& other);
    Vector(Vector&& other);

    ~Vector();
  };

} //  mds - my data structures

template<class T, class Allocator>
mds::Vector<T, Allocator>::Vector() : pVector_(nullptr), size_(0), capacity_(0) {}

template<class T, class Allocator>
mds::Vector<T, Allocator>::Vector(size_t size) : size_(size), capacity_(size) {
  pVector_ = alloc_.allocate(size_);

  for (size_t i = 0; i < size_; i += 1) {
    new (pVector_ + i) T();
  }
}

template<class T, class Allocator>
mds::Vector<T, Allocator>::Vector(size_t size, const T& value) : size_(size), capacity_(size) {
  pVector_ = alloc_.allocate(size_);

  for (size_t i = 0; i < size_; i += 1) {
    new (pVector_ + i) T(value);
  }
}

template<class T, class Allocator>
mds::Vector<T, Allocator>::Vector(const Vector& other) {
  this->size_ = other.size_;
  this->capacity_ = other.capacity_;
  
  this->pVector_ = alloc_.allocate(this->size_);

  for (size_t i = 0; i < this->size_; i += 1) {
    new (pVector_ + i) T(other.pVector_[i]);
  }
}

template<class T, class Allocator>
mds::Vector<T, Allocator>::Vector(Vector&& other) {
  this->size_ = other.size_;
  this->capacity_ = other.capacity_;

  this->pVector_ = other.pVector_;

  other.pVector_ = nullptr;

  other.capacity_ = 0;
  other.size_ = 0;
}

template<class T, class Allocator>
mds::Vector<T, Allocator>::~Vector() {
  if (this->pVector_ == nullptr) {
    return;
  }

  for (size_t i = 0; i < size_; i += 1) {
    pVector_[i].~T();
  }

  alloc_.deallocate(pVector_, capacity_);
}