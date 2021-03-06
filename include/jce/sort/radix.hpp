#pragma once
#include <vector>
#include <jce/utils.hpp>

namespace jce {
  namespace sort {
    template <typename T, typename Hash=std::hash<T>> // typename Func, 
    std::vector<T> radixSort(std::vector<T>& vec);

    namespace radix {
      template <typename Func, typename T>
      void getCounts(Func& func, T* source, T* end, size_t (&counts)[256], const size_t& size, const size_t& move, size_t& tmp);

      void computeIndicies(size_t (&counts)[256]);
      size_t& getIdx(size_t (&counts)[256], size_t& frontpos, const size_t& idx);

      template <typename Func, typename T>
      void makeBatches(Func& func, T* source, T* end, size_t (&counts)[256], const size_t& size, const size_t& move, size_t& tmp, size_t& frontpos);

      void zero(size_t* );
    }
  }
}

template <typename T, typename Hash=std::hash<T>> // typename Func, 
inline std::vector<T> jce::sort::radixSort(std::vector<T>& vec) {
  T* source = vec.data();
  T* output = new T[vec.size()];

  size_t counts[256];
  size_t offsets[256];
  size_t frontPos, tmp;

  Hash func;

  size_t size = sizeof(func(vec.front()));
  for (size_t idx=0; idx<size; idx++) {
    radix::getCounts  <Hash, T>(func, source, output, counts, vec.size(), idx*8, tmp);
    radix::computeIndicies(counts);
    radix::makeBatches<Hash, T>(func, source, output, counts, vec.size(), idx*8, tmp, frontPos);
    std::swap(source, output);
  }
  if (source == vec.data()) {
    delete[] output;
  }
  return std::vector<T>(source, source + vec.size());
}

template <typename Func, typename T>
inline void jce::sort::radix::getCounts(Func& func, T* source, T* end, size_t (&counts)[256], const size_t& size, const size_t& move, size_t& tmp) {
  setVal(&(counts[0]), (size_t)0, (size_t)256);

  for (size_t idx=0; idx<size; idx++) {
    tmp = (func(*(source+idx)) >> move)%256;
    counts[tmp]++;
  }
  return;
}
inline size_t& jce::sort::radix::getIdx(size_t (&counts)[256], size_t& frontpos, const size_t& idx) {
  if (idx == 0) return frontpos;
  return counts[idx-1];
}

inline void jce::sort::radix::computeIndicies(size_t (&counts)[256]) {
  for (size_t idx=1; idx<255; idx++) {
    counts[idx] = counts[idx] + counts[idx-1];
  }
}

template <typename Func, typename T>
inline void jce::sort::radix::makeBatches(Func& func, T* source, T* end, size_t (&counts)[256], const size_t& size, const size_t& move, size_t& tmp, size_t& frontpos) {
  frontpos = 0;
  for (size_t idx=0; idx<size; idx++) {
    tmp = (func(*(source+idx)) >> move)%256;
    size_t& pos = getIdx(counts, frontpos, tmp);
    end[pos] = *(source+idx);
    pos++;
  }
}