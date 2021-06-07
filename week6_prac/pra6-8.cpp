#include <iostream>
#include <map>
using std::cout, std::string;
int main()
{
    std::map<string, int> a{
        {"nn", 2}, {"ab", 1}, {"yu", 2}, {"ss", 4}};
    if (auto [it, flag]{a.insert({"nn", 3})}; flag)
    {
        auto [s, i]{*it};
        cout << s << " " << i << "\n";
    }
    cout << a.count("nn") << "\n";
    if (auto it{a.find("nn")}; it != a.end())
        a.erase(it);
}