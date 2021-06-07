#include <iostream>
template <typename T>
void print(const T &x)
{
    for (auto it = x.begin(); it != x.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}
