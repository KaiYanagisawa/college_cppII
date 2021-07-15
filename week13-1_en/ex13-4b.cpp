#include <iostream>
struct T
{
    int x;
    int y[2]{0};
};
void f() { double a{10.0 / 3.0}; }
void g()
{
    T a;
    std::cout << a.x << " " << a.y[0] << " " << a.y[1] << "\n";
}
int main()
{
    f();
    g();
}
