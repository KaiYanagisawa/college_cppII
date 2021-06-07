#include <iostream>
template <typename T>
class Point
{
public:
    T x, y;
    Point(T a, T b) : x{a}, y{b} {}
    bool operator<(const Point<T> &p) const
    {
        int p1 = (x * x + y * y) * (1 / 2);
        int p2 = (p.x * p.x + p.y * p.y) * (1 / 2);
        if (p1 < p2)
            return p2;
        else
            return p1;
    }
    /*
    bool operator==(const Point<T> &p) const
    {
        return x == p.x && y == p.y;
    }*/
};

template <typename T>
auto &
operator<<(std::ostream &o, const Point<T> &p)
{
    return o << "(" << p.x << "," << p.y << ")";
}