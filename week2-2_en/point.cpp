#include <iostream>
#include <iomanip>

std::ostream &operator<<(std::ostream &o, const Point &p)
{
    return o << "(" << p.get_name() << ": " << p.get_x() << ", " << p.get_y() << " "
             << ")"
             << "\n";
}

// std::istream &operator>>(std::istream &i, const Point &p)
// {
//     i >> p.get_name() >> p.get_x() >> p.get_y();
//     return i;
// }

// auto operator<=(const Point &p, const Point &q)
// {
//     int xx{}, yy{}, x1{}, y1{};
//     xx = q.get_x();
//     yy = q.get_y();
//     x1 = p.get_x();
//     y1 = p.get_y();
//     x1 = xx;
//     y1 = yy;
//     return x1, y1;
// }
