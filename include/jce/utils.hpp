#pragma once
#include <iostream>
#include <tuple>

namespace jce {
  template<typename T>
  void setVal(T* arr, const T& val, const size_t& size);

  // used in tuple iteration
  namespace sequence
  {
    // a templated sequence of numbers
    template<int... Is>
    struct seq { };
  
    template<int N, int... Is>
    struct gen_seq : gen_seq<N - 1, N - 1, Is...> { };
  
    template<int... Is>
    struct gen_seq<0, Is...> : seq<Is...> { };
  
    template<typename T, typename F, int... Is>
    void for_each(T&& t, F f, seq<Is...>);
  }
}

template <typename T> void jce::setVal(T* arr, const T& val, const size_t& size) { 
  for (size_t idx=0; idx<size; idx++) {
    *(arr+idx) = val;
  }
}

template<typename T, typename F, int... Is>
inline void jce::sequence::for_each(T&& t, F f, seq<Is...>) {
  auto l = {(f(std::get<Is>(t)), 0)...};
}