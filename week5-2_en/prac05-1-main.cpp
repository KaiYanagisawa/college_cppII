#include <iostream>
#include <deque>
#include <string>

int main()
{
    //
    // 必要な変数を宣言する
    //
    std::deque<std::string> que;
    // 5回の入力を実行
    for (int i = 0; i < 5; ++i)
    {
        //
        // ここのプログラムを作成する
        //
        std::cout << "Input: ";
        std::string s;
        std::cin >> s;
        //(1)sをdequeに入れる
        que.push_back(s);
        //(2)dequeの要素数によっては、
        //要素数を3以下にする
        if (que.size() > 3)
        {
            que.pop_front();
        }
        std::cout << "history: ";
        //dequeの中身を出力
        for (int i = 0; i < que.size(); i++)
        {
            std::cout << que[i] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}