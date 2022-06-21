#pragma once
#include "radix.hpp"
#include "insersion.hpp"
#include "merge.hpp"
#include "heap.hpp"
#include "quick.hpp"
#include "shell.hpp"
#include <algorithm>


namespace jce {
    namespace sort {
        size_t& getIdx(size_t& idx);

        template<typename T>
        void std(std::vector<T>& vec);
    }
}

inline size_t& jce::sort::getIdx(size_t& idx) {return idx;}

template<typename T>
void jce::sort::std(std::vector<T>& vec) {
    std::sort(vec.begin(), vec.end());
}