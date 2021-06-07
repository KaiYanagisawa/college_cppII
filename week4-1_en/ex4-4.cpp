//4-4
#include <vector>
#include <iostream>
using std::cout;
void print(const std::vector<int> &a)
{
    for (auto e : a)
        cout << e << " ";
    cout << "\n";
}
int main()
{
    std::vector a{8, 6, 5, 3, 2, 1};
    a.insert(a.begin(), 9);
    print(a);
    a.insert(a.begin() + 2, 7);
    print(a);
    a.erase(a.begin() + 3);
    print(a);
}