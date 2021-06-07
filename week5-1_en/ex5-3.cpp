#include <iostream>
#include <stack>
bool match(std::stack<char> &stk, char ch)
{
    bool flag{false};
    switch (ch)
    {
    case ']':
        if (stk.top() == '[')
        {
            flag = true;
        }
    case '}':
    case ')':
    }
}
int main()
{
    std::stack<char> stk;
    bool flag{true};
    char ch;
    while (flag && std::cin >> std::noskipws >> ch)
    {
        switch (ch)
        {
        case '[':
        case '{':
        case '(':
            stk.push(ch);
            break;
        case ']':
        case '}':
        case ')':
            flag = match(stk, ch);
            break;
        }
    }
    if (flag)
    {
        std::cout << "ok\n";
    }
    else
    {
        std::cout << "unmatch" << ch << "\n";
    }
}