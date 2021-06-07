#include <iostream>
#include <vector>
using std::cout, std::vector, std::string;
template <typename T>
void print_max(const T &a, const T &b)
{
    for (auto e : std::max(a, b))
    {
        cout << e << " ";
    }
    cout << "\n";
}
int main()
{
    vector x{3, 4, 2, 5, 8}, y{5, 4, 2};
    print_max(x, y);
    using namespace std::string_literals;
    print_max("xyz"s, "abcde"s);
    vector s{"ab"s, "cde"s}, t{"xyz"s, "0123"s};
    print_max(s, t);
}