#include <iostream>
#include <iterator>
#include <list>
int main()
{
    std::list x{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto it{x.begin()};
         it != x.end(); std::advance(it, 2))
    {
        std::cout << std::distance(x.begin(), it) << ":" << *it << " ";
    }
    std::cout << "\n";
}