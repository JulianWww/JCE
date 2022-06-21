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



int main(int argc, char **argv) {
  std::vector<size_t> vec = {2,1,4,9,0};
  jce::sort::insersion(vec);
  return 1;
}