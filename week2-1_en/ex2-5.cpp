#include <iostream>
#include "timedata13-impl.hpp"
int main()
{
    TimeData13 x{2, 5}, y{1, 75};
    std::cout << (x < y ? x.str() : y.str()) << "\n";
}