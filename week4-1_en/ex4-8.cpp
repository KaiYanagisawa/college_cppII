#include <iostream>
#include "./myvec.hpp"
template <typename T>
void print(const MyVec<T> &a)
{
    std::cout << a.capacity() << " [";
    for (size_t i = 0; i < a.size(); i++)
        std::cout << (i == 0 ? "" : " ") << a[i];
    std::cout << "]\n";
}
int main()
{
    MyVec<int> x, y;
    for (int i = 0; i < 5; i++)
        x.push_back(i);
    print(x);
    y = x;
    y.erase(y.begin(), y.begin() + 2);
    print(y);
}