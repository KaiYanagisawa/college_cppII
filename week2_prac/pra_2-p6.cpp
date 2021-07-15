#include <iostream>
class Timedata7
{
    int min, sec;

public:
    Timedata7(int s) { set(0, s); }
    Timedata7(int m, int s) { set(m, s); }
    void set(int m, int s)
    {
        min = m + s / 60;
        sec = s % 60;
    }
};
int main()
{
    Timedata7 t1{3, 50};
    t1.set(4, 70);
}