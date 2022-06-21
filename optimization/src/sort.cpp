#include <sort.hpp>
#include <config.hpp>
#include <jce/sort/sorts.hpp>
#include <jce/consoleUtils.hpp>

void optim::optimizeSort() {
    std::vector <size_t> insrt, std, radix;
    std::vector <size_t> sizes = SORT_ARR_SIZERS;
    for (size_t idx=0; idx<sizes.size(); idx++) {
        jce::consoleUtils::render_progress_bar(((double)idx) / ((float)sizes.size()));

        std::vector<size_t> vec = rndVec(sizes[idx]);
        insrt.push_back(getSortSpeed(jce::sort::insersion   <size_t>, vec));
        std.push_back  (getSortSpeed(jce::sort::std         <size_t>, vec));
        radix.push_back(getSortSpeed(jce::sort::radixSort   <size_t>, vec));
    }
    for (auto element: insrt) 
        std::cout << element << ", ";
    std::cout << std::endl;
    for (auto element: std) 
        std::cout << element << ", ";
    std::cout << std::endl;
    for (auto element: radix) 
        std::cout << element << ", ";
    std::cout << std::endl;
    return;
}

std::vector<size_t> optim::rndVec(const size_t& size) {
    std::vector<size_t> vec(size);
    for (auto& element : vec) {
        element = std::rand();
    }
    return vec;
}

bool optim::isSorted(const std::vector<size_t>& vec) {
  size_t max = vec.front();
  for (auto const& value: vec){
    if (max > value){
      return false;
    }
    max = value;
  }
  return true;
}