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
    std::vector<string> vs{"ac", "abc", "acc", "a c", "a0c", "a1c", "abd", "a3d", "axc", "a\nc"};
    for (auto e : vs)
        if (std::regex_match(e, r))
            cout << "\"" << e << "\"";
    cout << "\n";
}