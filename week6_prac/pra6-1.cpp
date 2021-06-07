#include <iostream>
#include <list>
struct Point
{
    int x, y;
};
int main()
{
    std::list<Point> pts{{3, 7}};
    auto org{pts.begin()};
    pts.push_front({1, 5});
    pts.insert(org, {2, 6});
    pts.push_back({4, 8});
    for (auto &p : pts)
        std::cout << "{" << p.x << ", " << p.y << "} ";
    std::cout << "\n{" << org->x << ", " << org->y << "}\n";
}