#include <iostream>
#include <set>
using std::cout, std::string;
int main()
{
    std::set<string> a{"nn", "ab", "yu", "ss"};
    if (auto [it, flag]{a.insert("nn")}; flag)
        cout << *it << " is inserted\n";
    cout << a.count("nn") << "\n";
    if (auto it{a.find("nn")}; it != a.end())
        a.erase(it);
}