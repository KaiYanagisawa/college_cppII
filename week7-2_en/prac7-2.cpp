//prac7-2.cpp
#include <iostream>
#include <map>
#include <list>
#include "random.hpp"
void make_hist(std::map<int, std::string> &m, std::list<double> l)
{
    for (auto it = l.begin(); it != l.end(); ++it)
    {
        for (int a = 0; a < 7; a++)
        {
            if (a <= *it && *it < a + 1)
            {
                m[a] = m[a] + '*';
                break;
            }
            if (7 <= *it)
            {
                m[7] = m[7] + '*';
                break;
            }
        }
    }
}
void erase_data(std::list<double> &l, double a, double b)
{
    auto iter{l.begin()};
    while (iter != l.end())
    {
        if (a <= *iter && *iter <= b)
            iter = l.erase(iter);
        else
            ++iter;
    }
}
void initialize(std::map<int, std::string> &m)
{
    m.clear();
    for (int a = 0; a <= 7; a++)
        m[a] = "";
}
int main()
{
    const int N{100};
    ExpDist x(0.5);
    std::list<double> l;
    for (int i = 0; i < N; i++)
    {
        l.insert(l.begin(), x.get());
    }
    std::map<int, std::string> m;
    for (int i = 0; i <= 7; i++)
    {
        m[i] = "";
    }
    make_hist(m, l);
    for (const auto [num, hist] : m)
    {
        std::cout << num << ' ' << hist << std::endl;
    }
    std::cout << std::endl;
    initialize(m);
    erase_data(l, 0, 1.5);
    make_hist(m, l);
    for (const auto [num, hist] : m)
    {
        std::cout << num << ' ' << hist << std::endl;
    }
    return 0;
}