#include <iostream>
#include "myvec.hpp"
template <typename T>
void print(const T &a)
{
    std::cout << a.capacity() << " [";
    for (size_t i = 0; i < a.size(); i++)
        std::cout << (i == 0 ? "" : " ") << a[i];
    std::cout << "]\n";
}
template <typename T>
void test(T &x)
{
    for (int i = 0; i < 5; i++)
    {
        x.insert(x.begin(), i);
        print(x);
    }
    x.insert(x.begin() + 3, 10);
    print(x);
    x.erase(x.begin() + 2);
    print(x);
}
int main()
{
    MyVec<int> x;
    test(x);
    std::cout << "\n";
    std::vector<int> y;
    test(y);
}