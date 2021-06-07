#include <vector>
#include "ex07print.hpp"
int main()
{
    std::vector x{3, 5, 3, 8, 3, 6, 3};
    auto it{x.begin()};
    while (it != x.end())
    {
        if (*it == 3)
            it = x.erase(it);
        else
            ++it;
    }
    print(x);
}