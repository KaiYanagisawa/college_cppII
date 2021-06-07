#include <iostream>
#include <vector>

//p6,7

template <typename T>
void f(std::vector<T> &b);

auto f()
{
    std::vector<T> b(3);
    return b;
}
a = f();

int main()
{
    std::vector<int> a{1, 2, 3} b{7, 8, 9, 10};
    print(a);
    print(b);
    a.swap(b);
    print(a);
    print(b);
}