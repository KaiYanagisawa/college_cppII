#include <iostream>
#include <vector>
#include <string>
template <typename T>
void size(std::string n)
{
    T x;
    T xa[5];
    std::cout << n << ":\t"
              << "sizeof(x) = " << sizeof(x) << ", "
              << "sizeof(x) = " << sizeof(xa) << "\n";
}

class CArray
{
    int a[10];
};
class Vector
{
    std::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
};
int main()
{
    size<int[10]>("int[10]");
    size<CArray>("CArray");
    size<std::vector<int> >("vector<int>");
    size<std::vector<double> >("vector<double>");
    size<Vector>("Vector ");
}
