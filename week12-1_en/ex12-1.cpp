#include <iostream>
using std::cout;
using std::string;
void find_all(string src, string sub)
{
    size_t tail{src.find_first_of(sub)};
    while (tail != string::npos)
    {
        if (head == tail)
        {
            cout << ": " << tail << "\n";
        }
        head = ++tail;
        tail = src.find_first_of(sub, head);
    }
}
int main()
{
    string a{"acbaabebcdacbac"};
    find_all(a, "ac");
    // find_all(a, "b");
    // find_all(a, "cb");
}