#include <algorithm>
#include <vector>
#include <iostream>
#include "./print.hpp"
int n;
bool rep(int x)
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
    std::replace_if(v.begin(), v.end(), rep, n);
    print(v);
    return 0;
}
