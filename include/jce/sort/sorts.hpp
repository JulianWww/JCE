#pragma once
#include "radix.hpp"
#include "insersion.hpp"
#include "merge.hpp"
#include "heap.hpp"
#include "quick.hpp"
#include "shell.hpp"
#include <algorithm>
#include <jce/config.hpp>


namespace jce {
    namespace sort {
        size_t& getIdx(size_t& idx);

        template<typename T>
        void std(std::vector<T>& vec);

        template<typename T, typename Hash = std::hash<T>>
        void smartSort(std::vector<T>& vec);
    }
}

inline size_t& jce::sort::getIdx(size_t& idx) {return idx;}

template<typename T>
void jce::sort::std(std::vector<T>& vec) {
    std::sort(vec.begin(), vec.end());
}

template<typename T, typename Hash>
void jce::sort::smartSort(std::vector<T>& vec) {
    if (vec.size() < SORT_SQUARELOG_HANDOF) {
        return insersion<T, Hash>(vec);
    }
    else if (vec.size() < SORT_LOGLIN_HANDOF) {
        return mergeSort<T, Hash>(vec);
    }
    else {
        return radixSort<T, Hash>(vec);
    }
}