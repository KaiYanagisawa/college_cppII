#include "ex14.hpp"
#include <memory>
using std::cout;
int main()
{
    auto p{std::make_unique<T[]>(1)};
    cout << p[0].get() << "\n";
    auto a{std::make_unique<T[]>(5)};
    a[0].set(3);
    a[1].set(2);
    for (int i = 0; i < 5; i++)
        cout << a[i].get() << " ";
    cout << "\n";
}