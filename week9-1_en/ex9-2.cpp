#include <iostream>
#include <vector>
#include <algorithm>
int num;
bool pred(int x)
{
    bool flag{num % x == 0};
    if (flag)
    {
        std::cout << "(" << x << ")";
    }
    return flag;
}
int main()
{
    std::vector a{2, 3, 5, 7, 11};
    while (std::cin >> num)
    {
        std::cout << num << " => ";
        auto ans{std::count_if(a.begin(), a.end(), pred)};
        std::cout << ":" << ans << "\n";
    }
    return 0;
}