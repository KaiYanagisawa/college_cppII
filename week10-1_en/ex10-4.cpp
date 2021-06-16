#include <algorithm>
#include <vector>
#include <iostream>
#include "./print.hpp"
int n;
bool rm(int x)
{
    return x > n;
}
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "usage: ./a.out \n";
        return 1;
    }
    std::vector<int> v{3, 2, 6, 1, 9, 4, 8, 6, 2};
    n = std::stoi(argv[1]);
    print(v);
    auto it{v.begin()};
    it = std::remove_if(v.begin(), v.end(), rm);
    v.erase(it, v.end());
    print(v);
    return 0;
}
