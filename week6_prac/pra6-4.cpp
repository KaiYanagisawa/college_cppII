#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    std::map<string, int> price{
        {"orange", 150},
        {"banana", 300},
        {"pineapple", 450}};
    cout << price.size() << ": ";
    for (auto &p : price)
        cout << "{" << p.first << ":" << p.second << "}";
    cout << "\n";
}