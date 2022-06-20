#pragma once
#include <iostream>

namespace jce {
  template<typename T>
  void setVal(T* arr, const T& val, const size_t& size);
  
  size_t& sortIdx(size_t&);
}

template <typename T> void jce::setVal(T* arr, const T& val, const size_t& size) { 
  for (size_t idx=0; idx<size; idx++) {
    *(arr+idx) = val;
  }
}
size_t& jce::sortIdx(size_t& val) {
  return val;
}