#include <sort.hpp>
#include <jce/sort/sorts.hpp>
#include <jce/consoleUtils.hpp>
#include <headers.hpp>

void optim::optimizeSort() {
    std::cout << "determening the insersion to merge hand of point";
    size_t handOfOne = getFirstShift();
    size_t handOfTwo = getSecondShift(handOfOne);

    config.addMacro("SORT_SQUARELOG_HANDOF", handOfOne);
    config.addMacro("SORT_LOGLIN_HANDOF",    handOfTwo);

    std::cout << jce::consoleUtils::fgreen << "\tSuccess" << jce::consoleUtils::reset << std::endl;
}

size_t optim::getFirstShift() {
    size_t size = 2;
    while (true) {
        auto vec = rndVec(size);
        size_t insertTime = getSortSpeed(jce::sort::insersion<size_t>, vec);
        size_t mergeTime  = getSortSpeed(jce::sort::mergeSort<size_t>, vec);

        if (insertTime > mergeTime) {
            return size;
        }
        size = size * 2;
    }
}
size_t optim::getSecondShift(size_t size) {
    while (true) {
        auto vec = rndVec(size);
        size_t radixTime  = getSortSpeed(jce::sort::radixSort<size_t>, vec);
        size_t mergeTime  = getSortSpeed(jce::sort::mergeSort<size_t>, vec);

        if (mergeTime > radixTime) {
            return size;
        }
        size = size * 2;
    }
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