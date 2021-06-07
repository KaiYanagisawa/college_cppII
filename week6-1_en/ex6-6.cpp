#include <iostream>
#include <string>
#include <map>
using std::cout, std::string;
int main()
{
    std::map<string, int> price{
        {"orange", 150}, {"tomato", 120}, {"banana", 300}, {"pineapple", 450}};
    for (auto [k, v] : price)
        cout << k << ": " << v << "\n";
}
