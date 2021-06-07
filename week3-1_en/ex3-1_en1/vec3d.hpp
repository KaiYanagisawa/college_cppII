#include <vector>
class Vec3d
{
    std::vector<int> vec;

public:
    Vec3d(int a = 0, int b = 0, int c = 0) : vec{a, b, c} {}
    int operator[](size_t i) const { return vec[i]; }
    int &operator[](size_t i) { return vec[i]; }
};