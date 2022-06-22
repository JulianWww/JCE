#include <iostream>
#include <jce/sort/sorts.hpp>

template<typename T>
bool isSorted(const std::vector<T>& vec) {
  T max = vec.front();
  for (auto const& value: vec){
    if (max > value){
      return false;
    }
    max = value;
  }
  return true;
}

std::vector<size_t> rndVec(const size_t& size) {
    std::vector<size_t> vec(size);
    for (auto& element : vec) {
        element = std::rand();
    }
    return vec;
}



int main(int argc, char **argv) {
  size_t size = 1;
  for (size_t idx=0; idx < 30; idx++) {
    auto vec = rndVec(size);
    jce::sort::mergeSort(vec);
    std::cout << idx << " " << isSorted(vec) << std::endl;

    size = size << 1;
  }
  return 1;
}