#include <iostream>
#include "./prsmall.hpp"

class Sales
{
    std::string name;
    int num;

public:
    Sales(std::string a, int b) : name(a), num(b) {}
    bool operator<(const Sales &p) const
    {
        return num < p.num;
    }
    friend auto &
    operator<<(std::ostream &o, const Sales &p)
    {
        return o << p.name << ": " << p.num;
    }
};

int main()
{
    Sales a{"abc", 40}, b{"xyz", 20};
    print_smaller(a, b);
}