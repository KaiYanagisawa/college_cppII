class TimeData13
{
    int min{}, sec{};

public:
    TimeData13(int m, int s);
    std::string str() const;
    bool operator<(const TimeData13 &) const;
};
