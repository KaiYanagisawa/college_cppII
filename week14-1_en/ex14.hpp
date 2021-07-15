#include <iostream>
class T
{
    int a;
    void log(std::string m)
    {
        std::cout << m << " " << &a << "\n";
    }

public:
    T(int b) : a{b} { log("ctor(int):   "); }
    T() : a{1} { log("ctor(default):"); }
    T(const T &x) : a{x.a} { log("ctor(copy):   "); }
    ~T() { log("dtor:     "); }
    int get() const { return a; }
    void set(int x) { a = x; }
};