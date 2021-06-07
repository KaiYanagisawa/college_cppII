#include <iostream>
#include <vector>
#include "./prsmall.hpp"

template <typename T>
auto &
operator<<(std::ostream &o, const std::vector<T> &v)
{
    for (auto &e : v)
        o << e << " ";
    return o;
}

int main()
{
    std::vector a{3, 4, 5, 6}, b{2, 4, 8, 1, 5};
    print_smaller(a, b);

    std::vector<double> c{2.4, 5.6}, d{2.4, 4.3, 9.0};
    print_smaller(c, d);
}