#pragma once
#include <iostream>

namespace jce {
  template<typename T>
  void setVal(T* arr, const T& val, const size_t& size);
}

template <typename T> void jce::setVal(T* arr, const T& val, const size_t& size) { 
  for (size_t idx=0; idx<size; idx++) {
    *(arr+idx) = val;
  }
}