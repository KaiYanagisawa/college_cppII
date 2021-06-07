#include <cmath>
template <typename T>
bool is_equal(T x, T y) { return x == y; }

template <>
bool is_equal(double x, double y)
{
    const double eps = 0.01;
    return std::abs(x - y) < eps;
}