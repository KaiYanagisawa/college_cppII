#include <iostream>
#include <set>
using namespace std;

int main()
{
    std::set<string> a;
    string s;
    while (cin >> s)
    {
        a.insert(a.begin(), s);
    }

    for (auto &e : a)
    {
        cout << e << " ";
    }
}