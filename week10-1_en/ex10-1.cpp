#include <algorithm>
#include <vector>
#include <iostream>
#include <math.h>
#include "./print.hpp"
int n = 1;
int moser()
{
    int a = (pow(n, 4) - 6 * pow(n, 3) + 23 * pow(n, 2) - 18 * n + 24) / 24;
    n++;
    return a;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "usage: ./a.out N";
        return 1;
    }
    int N{std::stoi(argv[1])};
    std::vector<int> x(N);
    std::generate(x.begin(), x.end(), moser);
    print(x);
    return 0;
}