#include <iostream>
#include <set>
using std::cout, std::string;
int main()
{
    std::multiset<string> a{"nn", "ab", "yu", "ss"};
    auto it{a.insert("nn")};
    cout << *it << " is inserted\n";
    cout << a.count("nn") << "\n";
    while ((it = a.find("nn")) != a.end())
        a.erase(it);
}