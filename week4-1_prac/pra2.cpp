//p10
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

    std::vector b{3, 2, 3, 4, 8};
    b.front() = 1;
    b.back() = 5;
    cout << b.front() << " " << b.back() << "\n";
    for (auto e : b)
        cout << e << " ";
    cout << "\n";
}
