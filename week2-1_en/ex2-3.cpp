#include <iostream>
class Ref
{
    int &x, y;

public:
    Ref(int &n, int num) : x(n), y(num) {}
    void set(int a, int b)
    {
        x = a;
        y = b;
    }
    void print() const
    {
        std::cout << x << " " << y << "\n";
    }
};

int main()
{
    int n{23};
    Ref s{n, 0}, t{n, 2};
    s.set(3, 1);
    s.print();
    t.print();
}