#include <string>
#include <sstream>
#include <iomanip>
class TimeData6
{
    int sec{};

public:
    void add(int m, int s);
    std::string str() const;
};
void TimeData6::add(int m, int s)
{
    sec += m * 60 + s;
}
std::string TimeData6::str() const
{
    std::ostringstream o;
    o << sec / 60 << ":" << std::setw(2) << std::setfill('0') << sec % 60;
    return o.str();
}