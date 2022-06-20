#include <iostream>
#include <jce/sort/radix.hpp>

int main(int argc, char **argv) {
  std::vector<size_t> vec = {9, 1024, 12, };
  std::vector<size_t> sorted = jce::sort::radixSort(vec);
  //char* arr = (char*)malloc(1024*1024*1024*1024);
  //delete arr;
  return 1;
}