#include <iostream>
template <typename T>
void print_smaller(T a, T b)
{
    if (a < b)
        std::cout << a << "\n";
    else
        std::cout << b << "\n";
}