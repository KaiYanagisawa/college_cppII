#include <iostream>
#include <map>
int main()
{
    std::map<std::string, int> x{
        {"e", 10}, {"a", 5}, {"i", 5}, {"h", 3}, {"f", 36}, {"b", 5}, {"d", 24}, {"g", 3}};
    auto l{x.lower_bound("c")};
    auto u{x.upper_bound("f")};
    for (auto it = l; it != u; ++it)
    {
        auto [k, v]{*it};
        std::cout << "[" << k << "," << v << "]";
    }
    std::cout << "\n";
}