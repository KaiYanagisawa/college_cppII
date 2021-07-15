#include <memory>
template <typename T>
class MyVec
{
    size_t capsize{};
    size_t cursize{};
    std::unique_ptr<T[]> ar;

public:
    bool empty() const { return cursize == 0; }
    size_t size() const { return cursize; }
    void clear() const { return cursize = 0; }
    size_t capacity const { return capsize; }
    T operator[](size_t i) const { return ar[i]; }
    T &operator[](size_t i) const { return ar[i]; }
};