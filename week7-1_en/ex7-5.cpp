#include <iostream>
#include <map>
int main()
{
    std::multimap<std::string, int> x{
        {"xn", 10}, {"ya", 5}, {"xn", 5}, {"zn", 3}, {"xn", 36}, {"sa", 5}, {"xn", 24}, {"tn", 3}};
    auto r{x.equal_range("xn")};
    for (auto it = r.first; it != r.second; ++it)
    {
        auto [k, v]{*it};
        std::cout << "[" << k << "," << v << "]";
    }
    std::cout << "\n";
}