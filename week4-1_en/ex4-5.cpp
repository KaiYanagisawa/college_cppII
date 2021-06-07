//4-5
#include <iostream>
#include <vector>
int main()
{
    std::vector a{1, 2, 3, 4, 5};
    for (auto it = a.begin(); it != a.end(); ++it)
    {
        auto e{*it};
        std::cout << e << "\n";
    }
    for (auto e : a)
        std::cout << e << "\n";
}