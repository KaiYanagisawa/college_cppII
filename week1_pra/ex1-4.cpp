#include <sstream>
#include <iostream>
#include <numeric>
class Frac
{
    int nume{0};
    int deno{1};

public:
    void set(int n, int d)
    {
        if (d < 0)
        {
            n = -n;
            d = -d;
        }
        int gcd{std::gcd(n, d)};
        nume = n / gcd;
        deno = d / gcd;
    }
    double value() const { return static_cast<double>(nume) / deno; }
    std::string str() const
    {
        std::ostringstream o;
        o << nume << "/" << deno;
        return o.str();
    }
};

void print(const Frac &f)
{
    std::cout << f.str() << " = " << f.value() << "\n";
}
int main()
{
    Frac a;
    print(a);
    a.set(2, 4);
    print(a);
    a.set(32, -128);
    print(a);
    a.set(-3, -9);
    print(a);
}