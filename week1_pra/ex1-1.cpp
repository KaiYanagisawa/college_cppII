#include <iostream>
#include "./timedata.hpp"
void print(const TimeData5 &t)
{
    std::cout << "経過時間:" << t.str() << "\n";
}
int main()
{
    TimeData5 t;
    t.add(3, 50);
    print(t);
    t.add(1, 15);
    print(t);
}