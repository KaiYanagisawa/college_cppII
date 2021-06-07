#include <list>
#include <vector>
#include <algorithm>
#include "ex07print.hpp"
template <typename T>
void find_and_insert(T &c, int f, int in)
{
    auto it{std::find(c.begin(), c.end(), f)};
    if (it != c.end())
    {
        std::cout << *it << "\n";
        c.insert(it, in);
    }
}
int main()
{
    std::list x{3, 5, 2, 8, 9, 6, 4};
    find_and_insert(x, 9, 10);
    print(x);
    std::vector y{3, 5, 2, 8, 9, 6, 4};
    find_and_insert(y, 6, 7);
    print(y);
    return 0;
}