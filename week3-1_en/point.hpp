#include <iostream>
template <typename T>
class Point
{
public:
    T x{}, y{};
    Point(T a, T b) : x{a}, y{b} {}
    bool operator<(const Point<T> &p) const
    {
        return (x * x + y * y) < (p.x * p.x + p.y * p.y);
    }
};
template <typename T>
auto &operator<<(std::ostream &o, const Point<T> &p)
{
    return o << "(" << p.x << "," << p.y << ")";
}