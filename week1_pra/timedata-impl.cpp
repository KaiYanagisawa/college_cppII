#include <sstream>
#include <iomanip>
#include "./timedata.hpp"
void TimeData5::add(int m, int s)
{
    min += m;
    sec += s;
    if (sec >= 60)
    {
        min += sec / 60;
        sec %= 60;
    }
}
std::string TimeData5::str() const
{
    std::ostringstream o;
    o << min << ":" << std::setw(2) << std::setfill('0') << sec;
    return o.str();
}