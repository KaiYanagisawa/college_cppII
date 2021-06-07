//4-3
#include <iostream>
#include <vector>
using std::cout;
int main()
{
    std::vector a{1, 2, 3, 4};
    auto it{a.begin()};
    cout << *it << " " << *(it + 1) << "\n";
    ++it;
    cout << *it << "\n";
    cout << a.end() - a.begin() << "\n";
}