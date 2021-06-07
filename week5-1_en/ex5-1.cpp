#include <iostream>
#include <stack>
int main()
{
    std::stack<int> s;
    for (int x; std::cin >> x;)
        s.push(x);
    while (!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << "\n";
}