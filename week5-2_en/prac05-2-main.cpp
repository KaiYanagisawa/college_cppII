#include <iostream>
#include <deque>
#include <string>

int main()
{
    std::deque<std::string> undo_stack;
    std::deque<std::string> redo_stack;
    std::string str{};

    while (true)
    {
        // cin で文字列を入力（str へ格納）
        std::cout << "Input Command: ";
        std::cin >> str;

        // 入力された文字列により処理を変更
        if (str == "exit")
        {
            // exit を入力すると終了
            std::cout << "Exit." << std::endl;
            return 0;
        }
        else if (str == "undo")
        {
            std::cout << "(Undo) ";
            //
            // undo を入力したときのプログラムを作成します
            //
            std::string to_redo{undo_stack.back()};
            undo_stack.pop_back();
            redo_stack.push_back(to_redo);
        }
        else if (str == "redo")
        {
            std::cout << "(Redo) ";
            //
            // redo を入力したときのプログラムを作成します
            //
            std::string to_undo{redo_stack.back()};
            redo_stack.pop_back();
            undo_stack.push_back(to_undo);
        }
        else
        {
            //
            // そのほかの文字列を入力したときのプログラムを作成します
            //
            undo_stack.push_back(str);
        }
        // 現在のコマンド（文字列）の表示用
        if (str == "undo" || str == "redo")
            str = "";
        std::cout << "Current Command: [" << str << "]\n";

        // undo_stack, redo_stack の中身を表示
        std::cout << "\n+------------------------------------+\n";
        std::cout << "undo_stack:";
        if (undo_stack.size() > 3)
            undo_stack.pop_front();
        for (auto s : undo_stack)
        {
            std::cout << " " << s;
        }
        std::cout << "\nredo_stack:";
        for (auto s : redo_stack)
        {
            std::cout << " " << s;
        }
        std::cout << "\n+------------------------------------+\n\n";
    }
}