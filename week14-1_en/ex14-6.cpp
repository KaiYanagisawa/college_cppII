#include <iostream>
#include <memory>
using Ptr = std::unique_ptr<struct Node>;
struct Node
{
    int value;
    Ptr nextp;
    Node(int a, Ptr &p)
        : value{a}, nextp{std::move(p)} {}
    ~Node() { std::cout << "dtor:  " << value << "\n"; }
};
class Stack
{
    Ptr ptr;

public:
    void push(int v)
    {
        ptr = std::make_unique<Node>(v, ptr);
    }
    void pop() { ptr = std::move(ptr->nextp); }
    int top() const { return ptr->value; }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << s.top() << "\n";
    s.pop();
    std::cout << s.top() << "\n";
}