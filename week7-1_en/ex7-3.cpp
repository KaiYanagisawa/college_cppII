#include <vector>
#include "ex07print.hpp"
int main()
{
    std::vector x{10, 3, 10, 8, 10, 10, 4};
    for (auto it = x.begin(); it != x.end(); ++it)
    {
        if (*it == 10)
        {
            it = x.insert(it, 5);
            ++it;
        }
    }
    print(x);
}