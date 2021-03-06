#include <stdint.h>

//  Windows
#ifdef _WIN32

#include <intrin.h>
inline uint64_t rdtsc(){
    return __rdtsc();
}

//  Linux/GCC
#else

inline uint64_t rdtsc(){
    unsigned int lo,hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

#endif
