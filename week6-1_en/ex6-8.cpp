#include <iostream>
#include <cctype>
#include <map>
auto normalize(std::string s)
{
    if (!std::isalpha(s.back()))
        s = s.substr(0, s.size() - 1);
    return s;
}
int main()
{
    std::map<std::string, int> words;
    for (std::string s; std::cin >> s;)
        ++words[normalize(s)];
    for (auto [w, c] : words)
        std::cout << w << ": " << c << "\n";
}