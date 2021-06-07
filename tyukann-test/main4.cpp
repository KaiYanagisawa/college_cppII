//main4.cpp
/* 空欄 4 必要なものをインクルード(選択問題) */
#include <iostream>
#include "timedata7.hpp"
int main()
{
    /* 空欄 5 オブジェクトの生成(テキスト穴埋め入力問題) */
    TimeData7 total;
    int m, s;
    char c;
    while (std::cin >> m >> c >> s)
        total.add(m, s);
    std::cout << total.str() << "\n";
}