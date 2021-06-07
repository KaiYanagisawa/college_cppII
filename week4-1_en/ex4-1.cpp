#include <iostream>
#include <vector>

using std::cout;

void print(const std::vector<int> &a)
{
    cout << a.size() << ", " << a.capacity() << ": ";
    for (auto e : a)
        cout << e << " ";
    cout << "\n";
}

int main()
{
    std::vector<int> a{1, 2, 3};
    print(a);
    a.pop_back();
    print(a);
    a.pop_back();
    print(a);
    a.clear();
    print(a);
}