#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "usage: " << argv[0] << " filename\n";
        return 1;
    }
    std::ifstream ifs(argv[1]);
    if (!ifs)
    {
        std::cout << "fileopen error: " << argv[1] << "\n";
        return 2;
    }
    std::cout << "----Read file : " << argv[1] << "\n";
    std::string line{};
    while (std::getline(ifs, line))
    {
        std::cout << line << "\n";
    }
    return 0;
}