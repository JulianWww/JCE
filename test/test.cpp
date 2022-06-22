#include <iostream>
#include <jce/bigint.hpp>

/*template<typename T>
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
*/


int main(int argc, char **argv) {
  Dodecahedron::Bigint a(999999999999999);
  Dodecahedron::Bigint b(1000000000000000);
  std::cout << a << std::endl;
  return 1;
}