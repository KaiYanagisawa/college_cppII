#include "ex14.hpp"
using std::cout;
int main()
{
    T *p{new T{1}};
    cout << p->get() << "\n";

    T *a{new T[5]{3, 2}};
    for (int i = 0; i < 5; i++)
        cout << a[i].get() << " ";
    cout << "\n";
    delete p;
}