#include <iostream>
#include <string>
#include <iomanip>

class Point
{
private:
    std::string name{"noname"};
    double x{0};
    double y{0};

public:
    Point(std::string n, double a, double b) : name(n), x(a), y(b) {}
    Point(double a, double b) : x(a), y(b) {}
    Point(std::string n) : name(n) {}
    Point() = default;
    Point(double a) : x(a) {}
    std::string get_name() const { return name; }
    int get_x() const { return x; }
    int get_y() const { return y; }
};
