#include <iostream>
#include <cmath>

void print(double a[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << a[i] << "\n";
    std::cout << "sizeof(a)=" << sizeof(a) << "\n";
}
int main()
{
    double x[10];
    for (int i = 0; i < 10; i++)
        x[i] = std::sqrt(1.0 + i);
    print(x, 10);
}