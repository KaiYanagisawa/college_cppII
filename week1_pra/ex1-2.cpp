#include <iostream>
#include "./timedata.hpp"
int main()
{
    TimeData5 total;
    int m, s;
    char c;
    while (std::cin >> m >> c >> s)
    {
        total.add(m, s);
    }
    std::cout << total.str();
}