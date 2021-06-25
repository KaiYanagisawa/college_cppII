#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
#include <regex>

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
    std::regex r{"[a-zA-Z+]+"};
    std::smatch m;
    while (ifs >> line)
    {
        std::regex_search(line, m, r);
        for (int i = 0; i < m.size(); i++)
        {
            std::cout << m[i].str() << "\n";
        }
    }
    return 0;
}