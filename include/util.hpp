#ifndef UTIL_H
#define UTIL_H

#include <ostream>

template <typename Value, typename... Rest>
void print(std::ostream& os, Value first, Rest... rest) {
    os << first << '\t';
    if constexpr (sizeof...(rest) > 0)
        print(os, rest...);
    else
        os << '\n';
}

#endif /* UTIL_H */
