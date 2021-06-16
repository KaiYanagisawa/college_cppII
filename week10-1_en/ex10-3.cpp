#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include "./print.hpp"
int n;
bool rep(int x)
{
    return x <= n;
}
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "usage: ./a.out n";
        return 1;
    }
    std::vector<int> x{3, 2, 6, 1, 9, 4, 8, 6, 2}, y{};
    n = std::stoi(argv[1]);
    print(x);
    std::copy_if(x.begin(), x.end(), std::back_inserter(y), rep);
    print(y);
    return 0;
}
