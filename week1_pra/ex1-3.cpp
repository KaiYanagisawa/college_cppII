#include <iostream>
#include "./timedata6.hpp"
int main()
{
    TimeData6 total;
    int m, s;
    char c;
    while (std::cin >> m >> c >> s)
    {
        total.add(m, s);
    }
    std::cout << total.str();
}