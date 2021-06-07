#include <iostream>
#include <string>
#include <iomanip>

class Point{
    private:
        std::string name{"noname"};
        double x{0};
        double y{0};
    public:
        Point(std::string n, double a, double b){name=n;x=a,y=b;} 
        Point(double a,double b){name;x=a;y=b;}
        Point(std::string n){name=n;x;y;}  
        Point(){name;x;y;}
        Point(double a){name;x=a;y;}
        std::string get_name() const {return name;}
        int get_x() const {return x;}
        int get_y() const {return y;}
};

