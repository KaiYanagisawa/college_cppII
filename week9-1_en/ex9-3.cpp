#include <algorithm>
#include <iostream>
#include <deque>
int main()
{
    std::deque d{4, 2, 1, 5, 9, 8, 9};
    auto [min, max]{std::minmax_element(d.begin(), d.end())};
    double sum{0};
    int num{0};
    //この後を埋める
    //出力:trimmean=4.75
    for (auto &deq : d)
    {
        if (deq != *min && deq != *max)
        {
            sum += deq;
            num++;
        }
    }
    std::cout << "trimmean = " << sum / num;
}