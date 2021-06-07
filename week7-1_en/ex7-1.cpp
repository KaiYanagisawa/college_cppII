#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <list>
template <typename T>
void print(const T &x)
{
    for (auto it = x.begin(); it != x.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}
int main()
{
    std::vector a{1, 2, 3, 4, 5};
    std::deque b{3, 5, 4, 6, 8};
    std::list c{7, 4, 2, 1, 9};
    std::set d{6, 2, 8, 6, 2};
    print(a);
    print(b);
    print(c);
    print(d);
}