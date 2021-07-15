#include <iostream>
#include <array>
void count(int *num_p, int size, int *cnt_p)
{
    for (int i = 0; i < size; ++i)
    {
        if (num_p[i] < 10)
            cnt_p[0]++;
        else if (num_p[i] < 100 && num_p[i] >= 10)
            cnt_p[1]++;
        else if (num_p[i] < 1000 && num_p[i] >= 100)
            cnt_p[2]++;
        else if (num_p[i] < 10000 && num_p[i] >= 1000)
            cnt_p[3]++;
    }
}
int main()
{
    std::array num = {0, 1001, 32, 55, 961, 872, 3, 455, 606, 999, 1055, 87};
    std::array<int, 4> cnt{0};
    count(&num[0], num.size(), &cnt[0]);
    for (int i = 0; i < cnt.size(); i++)
    {
        if (i == 0)
            std::cout << i + 1 << " digit:" << cnt[i] << "\n";
        else
            std::cout << i + 1 << " digits:" << cnt[i] << "\n";
    }
    std::cout << "\n";
}