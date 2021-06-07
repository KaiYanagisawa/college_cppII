#include <vector> //myvec.hpp
template <typename T>
class MyVec
{
    size_t capsize{};
    size_t cursize{};
    std::vector<T> ar;

public:
    bool empty() const { return cursize == 0; }
    size_t size() const { return cursize; }
    void clear() const { return cursize = 0; }
    size_t capacity() const { return capsize; }
    T operator[](size_t i) const { return ar[i]; }
    T &operator[](size_t i) { return ar[i]; }

    void push_back(const T &x)
    {
        if (cursize == capsize)
        {
            capsize = (capsize == 0) ? 1 : 2 * capsize;
            std::vector<T> n(capsize);
            for (size_t i = 0; i < cursize; i++)
                n[i] = ar[i];
            ar.swap(n);
        }
        ar[cursize] = x;
        ++cursize;
    }
    void pop_back() { --cursize; }
    size_t begin() { return 0; }
    size_t end() { return cursize; }
    void swap(MyVec<T> &x)
    {
        ar.swap(x);
        std::swap(capsize, x.capsize);
        std::swap(cursize, x.cursize);
    }
    size_t erase(size_t pos)
    {
        if (pos >= cursize)
            return cursize;
        for (size_t i = pos; i < cursize - 1; i++)
            ar[i] = ar[i + 1];
        --cursize;
        return pos;
    }
    size_t insert(size_t pos, const T &v)
    {
        if (pos > cursize)
            pos = cursize;
        if (cursize == capsize)
        {
            capsize = (capsize == 0) ? 1 : 2 * capsize;
            std::vector<T> n(capsize);
            for (size_t i = 0; i < pos; i++)
                n[i] = ar[i];
            for (size_t i = pos; i < cursize; i++)
                n[i + 1] = ar[i];
            ar.swap(n);
        }
        else
        {
            for (size_t i = cursize; i > pos; i--)
                ar[i] = ar[i - 1];
        }
        ar[pos] = v;
        ++cursize;
        return pos;
    }
    void erase(size_t first, size_t last)
    {
        if (last >= cursize)
            last = cursize;
        if (first < last)
        {
            for (size_t i = first, j = last; j < cursize; i++, j++)
                ar[i] = ar[j];
            cursize -= (last - first);
        }
    }
};