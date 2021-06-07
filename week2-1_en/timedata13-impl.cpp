#include <iomanip>
#include <sstream>
#include "timedata13-impl.hpp"
TimeData13::TimeData13(int m, int s) : min{m + s / 60}, sec{s % 60} {}
std::string TimeData13::str() const
{
    std::ostringstream o;
    o << min << ":" << std::setw(2) << std::setfill('0') << sec;
    return o.str();
}
bool TimeData13::operator<(const TimeData13 &data) const
{
    return min < data.min || (min == data.min && sec < data.sec);
}