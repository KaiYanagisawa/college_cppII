#include <iostream>
class TimeData8
{
public:
    int min{1}, sec{30};
    TimeData8() { min = 1, sec = 30; }
    TimeData8(int m, int s)
    {
        min = m + s / 60;
        sec = s % 60;
    }
};
int main()
{
    TimeData8 t1{3, 65};
    std::cout << t1.min << ":" << t1.sec << "\n";
    TimeData8 t2;
    std::cout << t2.min << ":" << t2.sec << "\n";
}