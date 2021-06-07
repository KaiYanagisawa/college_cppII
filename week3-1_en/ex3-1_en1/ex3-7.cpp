#include <iostream>
#include "point.hpp"

int main()
{
    Point<int> a{3, -4}, b{3, -4};
    if (a == b)
        std::cout << "a,b =>" << a << "\n";
}