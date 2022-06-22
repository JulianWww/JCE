#pragma once
#include <jce/sort/sorts.hpp>
#include <timer.hpp>
#include <jce/consoleUtils.hpp>

namespace optim {
    void optimizeSort();

    size_t getFirstShift(); // insersion to merge sort shift point
    size_t getSecondShift(size_t size); // merge to radix sort shift point

    std::vector<size_t> rndVec(const size_t& size);

    template <typename Func>
    size_t getSortSpeed(Func func, std::vector<size_t> vec);
    bool isSorted(const std::vector<size_t>& vec);
}

template <typename Func> 
inline size_t optim::getSortSpeed(Func func, std::vector<size_t> vec) {
    size_t start = rdtsc();
    func(vec);
    size_t end = rdtsc();
    if (!isSorted(vec)){
        std::cout << jce::consoleUtils::fred << "Error" << jce::consoleUtils::reset << std::endl;
    }
    return end - start;
}