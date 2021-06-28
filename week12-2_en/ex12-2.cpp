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
    int line_number{0}, word_number{0};
    std::map<std::string, int> map;
    while (std::getline(ifs, line))
    {
        auto begin{line.cbegin()}, end{line.cend()};

        std::sregex_token_iterator p{begin, end, r, 0};
        std::sregex_token_iterator e;
        ++line_number;

        for (; p != e; ++p)
        {
            map[*p] += 1;
            ++word_number;
        }
        std::cout << "\n";
    }
    for (auto [k, v] : map)
    {
        std::cout << k << " : " << v << "\n";
    }

    std::cout << "---------\n";

    std::cout << "Total line num : " << line_number << "\n";
    std::cout << "Total word count : " << word_number << "\n";
    std::cout << "map.size : " << map.size() << "\n";
    return 0;
}