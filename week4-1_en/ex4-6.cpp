#include <iostream> //ex4-6.cpp
#include "myvec.hpp"
void print(const MyVec<int> &a)
{
    std::cout << a.capacity() << " [";
    for (size_t i = 0; i < a.size(); i++)
        std::cout << (i == 0 ? "" : " ") << a[i];
    std::cout << "]\n";
}
int main()
{
    MyVec<int> x;
    for (int i = 0; i < 5; i++)
    {
        x.push_back(i);
        print(x);
    }
    x.insert(x.begin() + 3, 10);
    print(x);
    x.erase(x.begin() + 2);
    print(x);
}