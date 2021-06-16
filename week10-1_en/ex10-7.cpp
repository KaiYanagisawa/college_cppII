#include <algorithm>
#include <random>
#include <vector>
#include "print.hpp"

int main()
{
    std::vector a{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::mt19937 engine{std::random_device{}()};
    std::shuffle(a.begin(), a.end(), engine);
    print(a);

    std::partial_sort(a.begin(), a.begin() + 4, a.end());
    print(a);
}