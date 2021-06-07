#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
using std::cout;
int main()
{
    int num;
    std::vector a{1, 2, 3, 1, 2, 2, 3, 4};
    while (std::cin >> num)
    {
        std::cout << "count(" << num << "):" << std::count(a.begin(), a.end(), num) << "\n";
    }
    return 0;
}