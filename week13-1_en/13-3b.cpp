#include <iostream>

void f()
{
    double a{0.0};
}
void g()
{
    int x, y[2];
    std::cout << x << " "
              << y[0] << " "
              << y[1] << "\n";
}

int main()
{
    f();
    g();
}