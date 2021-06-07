#include <iostream>
#include "./ex3-6.hpp"
int main()
{
    Vec3d x{1, 2, 1};
    x[2] = 3;
    std::cout << x[2] << "\n";
}