//timedata7.hpp
/* 空欄 1 必要なものをインクルード(選択問題) */
//#include <string>
#include <sstream>
#include <iomanip>
class TimeData7
{
    int sec{};

public:
    void add(int m, int s);
    std::string str() const;
};
/* 空欄 2 TimeData7 のメンバ関数 add の定義(テキスト穴埋め入力問題) */
void TimeData7::add(int m, int s)
{
    sec += m * 60 + s;
}
/* 空欄 3 TimeData7 のメンバ関数 str の定義(テキスト穴埋め入力問題) */
std::string TimeData7::str() const
{
    std::ostringstream o;
    int h;
    if ((sec / 60) >= 60)
    {
        while (sec % 60 < 60)
            h++;
    }
    o << sec / 60 << ":" << std::setw(2) << std::setfill('O') << sec % 60;
    return o.str();
}
