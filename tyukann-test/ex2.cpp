#include <iostream>
#include <vector>
using std::cout, std::cin, std::vector;

void print(const vector<double> &v)
{
    cout << v.size() << "," << v.capacity() << ": ";
    for (auto e : v)
        cout << e << " ";
    cout << "\n";
}

int main()
{
    vector<double> x{3.3, 2.2, 1.1}, y{5.5, 6.6, 4.4};
    print(x);
    print(y);

    x.pop_back();
    y.pop_back();
    for ()
        print(x);
    print(y);
}