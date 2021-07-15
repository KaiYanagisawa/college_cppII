#include <iostream>
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
class Single
{
    int a;
};
class Pair
{
    int a;
    double b;
};
int main()
{
    size<int>("int");
    size<double>("double");
    size<Single>("Single");
    size<Pair>("Pair");
}