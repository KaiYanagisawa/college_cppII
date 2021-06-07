#include <iostream>
#include <vector>
#include <string>
using std::cout, std::cin, std::vector, std::string;

int main()
{

    vector<string> words;
    string s{};

    //vector wordsへ文字列を格納していく．
    while (s != "." && cout << "Input a word --> " && cin >> s)
    {
        if (s != ".")
            words.push_back(s);
    }

    //wordsに格納された文字列を表示
    for (int i = 0; i < words.size(); i++)
    {
        if (i != words.size() - 1)
            cout << words[i] << " ";
        else
            cout << words[i] << ".";
    }
}