#pragma once
#include <vector>

namespace jce {
    namespace sort {

        template <typename T, typename Hash = std::hash<T>>
        void quick(std::vector<T>& vec);

        namespace quickSort {

            template <typename T, typename Hash>
            void sort(std::vector<T>& vec, size_t low, size_t hi);

            template <typename T, typename Hash>
            size_t partition(std::vector<T>& vec, size_t& low, size_t& hi);
        }
    }
}

template <typename T, typename Hash>
void jce::sort::quick(std::vector<T>& vec) {
    quickSort::sort<T, Hash>(vec, 0, vec.size());
}

template <typename T, typename Hash>
void jce::sort::quickSort::sort(std::vector<T>& vec, size_t low, size_t hi) {
    if (low >= hi || low < 0)
        return;

    size_t p = partition<T, Hash>(vec, low, hi);

    if (p!=0) { sort<T, Hash>(vec, low,   p - 1); }
    
    sort<T, Hash>(vec, p + 1, hi);
}

template <typename T, typename Hash>
size_t jce::sort::quickSort::partition(std::vector<T>& vec, size_t& low, size_t& hi) {
    size_t pivot = vec[hi];
    size_t i = low - 1;

    for (size_t j=low; j<hi; j++) {
        if (vec[j] <= pivot) {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }
    i++;
    std::swap(vec[i], vec[hi]);
    return i;
}