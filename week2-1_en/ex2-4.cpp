#include <iostream>
#include <iomanip>
#include "timedata12.hpp"
std::ostream &operator<<(std::ostream &out, const TimeData12 &t)
{
    return out << t.getm() << ":" << t.gets();
}
int main()
{
    TimeData12 x{2, 5}, y{1, 75};
    std::cout << x << ", " << y << "\n";
}