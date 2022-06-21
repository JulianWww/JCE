#pragma once

namespace jce {
    namespace sort {

        template <typename T, typename Hash = std::hash<T>>
        void heap(std::vector<T>& vec);

        namespace _heap {

            template <typename T, typename Hash = std::hash<T>>
            void heapify(std::vector<T>& vec, const size_t& size);

            template <typename T, typename Hash = std::hash<T>>
            void shiftUp(T* arr, size_t& start, size_t& end);

            size_t iParent(const size_t& i);
            size_t iLeftChild(const size_t& i);
            size_t iRightChild(const size_t& i);
        }
    }
}

template <typename T, typename Hash>
inline void jce::sort::heap(std::vector<T>& vec) {
    _heap::heapify<T, Hash>(vec, vec.size());
    for (size_t end=vec.size()-1; end>0; end--) {
        std::swap(vec[end], vec[0]);
        _heap::heapify<T, Hash>(vec, end);
    }
}

template <typename T, typename Hash>
inline void jce::sort::_heap::heapify(std::vector<T>& vec, const size_t& size) {
    size_t null = 0;
    for (size_t end=1; end < size; end++) {
        shiftUp<T, Hash>(vec.data(), null, end);
    } 
}

template <typename T, typename Hash = std::hash<T>>
inline void jce::sort::_heap::shiftUp(T* arr, size_t& start, size_t& end) {
    for (size_t child=end; child > start;) {
        size_t parent = iParent(child);
        if (arr[parent] < arr[child]) {
            std::swap(arr[parent], arr[child]);
            child = parent;
        }
        else{
            return;
        }
    }
}

inline size_t jce::sort::_heap::iParent(const size_t& i)     { return (i-1)/2; }
inline size_t jce::sort::_heap::iLeftChild(const size_t& i)  { return 2*i + 1; }
inline size_t jce::sort::_heap::iRightChild(const size_t& i) { return 2*i + 2; }