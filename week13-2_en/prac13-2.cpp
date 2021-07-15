#include <iostream>
#include <cstring>
#include <iomanip>
void connect_str(const char *s1, const char *s2, char *co)
{
    std::cout << co[2];
}

int main()
{
    std::cout << "input strings --> ";
    //２つの文字列を格納できる２次元配列を宣言
    char s1[2][4];
    //連結させた文字列を格納する配列を定義
    char s2;
    //cinから文字列を読み込み
    char co;
    std::cin >> co;
    //connect_str関数を呼び出し
    connect_str(&s1[0][0], &s2, &co);
    //連結させた文字列を出力（一行）
    std::cout << s2;
}