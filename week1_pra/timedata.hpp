#include <string>
class TimeData5
{
    int min{};
    int sec{};

public:
    void add(int m, int s);
    std::string str() const;
};