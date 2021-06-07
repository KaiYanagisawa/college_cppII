#include <iostream>
#include "./equal.hpp"

int main()
{
    if (is_equal(1 + 2, 3))
        std::cout << "ok\n";
    if (is_equal(0.1 + 0.2, 0.3))
        std::cout << "ok\n";
}