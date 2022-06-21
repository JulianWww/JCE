#pragma once
#include <vector>

#define SHELL_GAPS_CIURA {701, 301, 132, 57, 23, 10, 4, 1}

namespace jce {
    namespace sort {

        template <typename T, typename Hash = std::hash<T>>
        void _shell(std::vector<T>& vec);

        template <typename T, typename Hash = std::hash<T>>
        void shell(std::vector<T>& vec);

        template <typename T, typename Hash = std::hash<T>>
        void shell(std::vector<T>& vec, std::vector<size_t> gaps);
    }
}

template <typename T, typename Hash>
void jce::sort::_shell(std::vector<T>& vec) {
    shell<T, Hash>(vec, SHELL_GAPS_CIURA);
}

template <typename T, typename Hash>
void jce::sort::shell(std::vector<T>& vec) {
    shell<T, Hash>(vec, SHELL_GAPS_CIURA);
}

template <typename T, typename Hash>
void jce::sort::shell(std::vector<T>& vec, std::vector<size_t> gaps) {
    for (auto const& gap : gaps) {
        for (size_t i = gap; i < vec.size(); i++) {
            T tmp = vec[i];
            size_t j=i;
            for (; vec[j-gap] > tmp && j>=gap; j-=gap) {
                vec[j] = vec[j-gap];
            }
            vec[j] = tmp;
        }
    }
}