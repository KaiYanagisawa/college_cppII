#include <iostream>
#include <iomanip>

class Timedata11{
        int min{}, sec{};
    public:
        Timedata11(int m, int s):min{m+s/60},sec{s%60}{}
        int getm() const {return min;}
        int gets() const {return sec;}
        std::string str() const{
            std::ostringstream o;
            o << min << ":"<<std::setw(2) 
              << std::setfill('0')<<sec;
            return o.str();
        }
};
auto
operator+(const Timedata11& a, const Timedata11& b){
    return Timedata11{a.getm()+b.getm(),a.gets()+b.gets()};
}
Timedata11
operator-(const Timedata11& a, const Timedata11& b){
    return {a.getm()-b.getm(),a.gets()-b.gets()};
}
auto&
operator<<(std::ostream& out, const Timedata11& t){
    return out<<t.str();
}
int main(){
    Timedata11 x{3,35}, y{2,10};
    std::cout <<x+y<<"\n";
    std::cout<<x-y<<"\n"; 
}
