#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "usage: " << argv[0] << " regex\n";
        return 1;
    }
    string rs{argv[1]};
    std::regex r{rs};
    std::vector<string> lst{"ac", "aaac", " aac ", "akb", "ac ccc", "anc "};

    for (auto &s : lst)
        if (std::regex_match(s, r))
            cout << s << ", ";
    cout << "\n";
    for (auto &s : lst)
        if (std::regex_search(s, r))
            cout << s << ", ";
    cout << "\n";
}