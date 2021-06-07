//prac7-1.cpp
#include <iostream>
#include <set>
#include "random.hpp"
double med(std::multiset<double> ms)
{
    //1.適切に埋めよ
    int m_half = ms.size() / 2;
    double med{};
    if (ms.size() % 2 == 0)
    {
        auto it_be{std::next(ms.begin(), (ms.size() / 2) - 1)};
        auto it_en{std::prev(ms.end(), (ms.size() / 2 - 1))};
        for (auto it = it_be; it != it_en; ++it)
        {
            med = med + *it;
        }
        return med / 2;
    }
    else
    {
        auto it{std::next(ms.begin(), m_half)};
        return *it;
    }
}
double mean(std::multiset<double> ms)
{
    //2.適切に埋めよ
    double sum{};
    for (const double i : ms)
    {
        sum = sum + i;
    }
    return sum / ms.size();
}
double var(std::multiset<double> ms)
{
    //3.適切に埋めよ
    double sum{};
    double aver{};
    double p{};
    for (const double i : ms)
    {
        sum = sum + i;
    }
    for (const double i : ms)
    {
        p = p + ((i - aver) * (i - aver));
    }
    return p / ms.size();
}

int main()
{
    const int N{10};
    ExpDist x(0.5);
    std::multiset<double> ms;
    for (int i = 0; i < N; i++)
    {
        ms.insert(x.get());
    }
    for (const double e : ms)
    {
        std::cout << e << std::endl;
    }
    std::cout << "median=" << med(ms) << std::endl;
    std::cout << "mean=" << mean(ms) << std::endl;
    std::cout << "variance=" << var(ms) << std::endl;
    std::cout << "difference=" << med(ms) / mean(ms) - log(2) << std::endl;

    return 0;
}