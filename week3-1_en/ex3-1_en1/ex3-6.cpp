#include <iostream>
#include "vec3d.hpp"

int main()
{
    Vec3d x{1, 2, 1};
    x[2] = 3;
    for (int i = 0; i < 3; i++)
        std::cout << x[i] << "\n";
}