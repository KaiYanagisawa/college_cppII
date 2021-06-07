class TimeData12
{
    int min{}, sec{};

public:
    TimeData12(int m, int s) : min{m + s / 60}, sec{s % 60} {}
    int getm() const { return min; }
    int gets() const { return sec; }
};
