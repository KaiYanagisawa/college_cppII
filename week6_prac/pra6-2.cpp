#include <iostream>
#include <list>
#include <vector>
#include <dist
int main()
{
    std::list<int> memb{2, 5}, sub{3, 7, 9};
    auto old1{memb.begin()}, old2{sub.begin()};
    std::vector<int *> org;
    for (auto &p : memb)
        org.push_back(&p);
    for (auto &p : sub)
        org.push_back(&p);
    memb.merge(sub);
    UniDist r(10, 20);
    for (int i = 0; i < 10; i++)
    {
        memb.insert(old1, r.get());
        memb.insert(old2, r.get());
    }
    using std::cout;
    for (auto &e : memb)
        cout << e << " ";
    cout << "\n";
    for (auto e : org)
        cout << *e << " ";
    cout << "\n";
}
