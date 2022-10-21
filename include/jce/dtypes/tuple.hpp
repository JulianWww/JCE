#include <tuple>
#include <jce/utils.hpp>

namespace jce {
        // run the function f for every element in the tuple t
    template<typename... T, typename F>
    void for_each_in_tuple(std::tuple<T...>& t, F f);
}

template<typename... T, typename F>
inline void jce::for_each_in_tuple(std::tuple<T...>& t, F f) {
    jce::sequence::for_each(t, f, jce::sequence::gen_seq<sizeof...(T)>());
}
