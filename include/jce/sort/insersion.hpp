#pragma once

namespace jce {
    namespace sort {
        template <typename T, typename Hash = std::hash<T>>
        void insersion(std::vector<T>&);
    }
}

template <typename T, typename Hash = std::hash<T>> 
inline void jce::sort::insersion(std::vector<T>& vec){
    for (size_t idx = 1; idx < vec.size(); idx++){
        T tmp = vec[idx];
        size_t other=idx-1;
        while(other!=-1 && Hash{}(tmp) <= Hash{}(vec[other])){
            vec[other+1] = vec[other];
            other--;
        }
        vec[other+1] = tmp;
    }
}
