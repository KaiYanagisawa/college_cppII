//適切なヘッダファイルを指定する
#include <iostream>
#include <vector>
#include <algorithm>
//関数predを定義する
bool pred(int x)
{
    int num;
    bool flag{x % 2 == 0 || x % 3 == 0};
    return flag;
}

int main()
{
    std::vector a{2, 6, 18, 17, 12, 3};
    auto it{std::find_if_not(a.begin(), a.end(), pred)};
    std::cout << *it << "\n";
}