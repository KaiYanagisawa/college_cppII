#include <iostream>
#include <vector>

using std::cout;

int main()
{
    std::vector b{3, 2, 3, 4, 8};
    b.front() = 1;
    b.back() = 5;
    cout << b.front() << " " << b.back() << "\n";
    for (auto e : b)
        cout << e << " ";
    cout << "\n";
}