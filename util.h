#ifndef UTIL_H
#define UTIL_H

#include <random>
#include <type_traits>

namespace util {
    template <typename IntType = int>
    IntType rand_range(IntType start, IntType end) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(start, end);
        return dist(rng);
    }

    template <typename RealType, typename = typename std::enable_if<std::is_floating_point<RealType>::value>::type>
    RealType rand_range_f(RealType start, RealType end) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_real_distribution<RealType> dist(start, end);
        return dist(rng);
    }
}

#endif //UTIL_H
