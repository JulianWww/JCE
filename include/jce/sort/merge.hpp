#pragma once
#include <iostream>
#include <vector>

namespace jce {
    namespace sort {
        
        template <typename T, typename Hash=std::hash<T>>
        std::vector<T> mergeSort(std::vector<T>& vec);

        namespace merge {
            template <typename T, typename Hash>
            void split(T* arrA, T* arrB, const size_t& iBegin, const size_t& iEnd);

            template <typename T, typename Hash>
            void merge(T* arrA, T* arrB, const size_t& iBegin, const size_t& iMiddle, const size_t& iEnd);

            template <typename T>
            void copyArray(T* from, T* to, const size_t& iBegin, const size_t& iEnd);
        }
    }
}

template <typename T, typename Hash>
inline std::vector<T> jce::sort::mergeSort(std::vector<T>& vec) {
    T* arrA = vec.data();
    T* arrB = new T[vec.size()];
    merge::copyArray(arrA, arrB, 0, vec.size());
    merge::split<T, Hash>(arrA, arrB, (size_t)0, vec.size());
    return std::vector<T>(arrB, arrB + vec.size());
}

template <typename T, typename Hash>
inline void jce::sort::merge::split(T* arrA, T* arrB, const size_t& iBegin, const size_t& iEnd) {
    if (iEnd - iBegin <= 1)
        return;
    size_t iMiddle = (iEnd + iBegin) / 2;
    split<T, Hash>(arrB, arrA, iBegin, iMiddle);
    split<T, Hash>(arrB, arrA, iMiddle, iEnd);

    merge<T, Hash>(arrA, arrB, iBegin, iMiddle, iEnd);
}

template <typename T, typename Hash>
inline void jce::sort::merge::merge(T* arrA, T* arrB, const size_t& iBegin, const size_t& iMiddle, const size_t& iEnd) {
    size_t i = iBegin;
    size_t j = iMiddle;

    for (size_t k = iBegin; k<iEnd; k++) {
        if (i < iMiddle && (j >= iEnd || Hash{}(arrA[i]) <= Hash{}(arrA[j]))) {
            arrB[k] = arrA[i];
            i++;
        }
        else {
            arrB[k] = arrA[j];
            j++;
        }
    }
}

template <typename T>
inline void jce::sort::merge::copyArray(T* from, T* to, const size_t& iBegin, const size_t& iEnd) {
    for (size_t idx=iBegin; idx < iEnd; idx++)
        to[idx] = from[idx];
}