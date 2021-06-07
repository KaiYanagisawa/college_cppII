#include <iostream>
#include <math.h>
template <typename T>
class Vec
{
    std::string name;
    T x, y, z;

public:
    Vec(std::string s, T a, T b, T c) : name{s}, x{a}, y{b}, z{c} {}
    std::string get_name() const { return name; }
    double get_x() const { return x; }
    double get_y() const { return y; }
    double get_z() const { return z; }
    void print() const;
    std::string get_n() const;
    double length() const;
    double inner_product() const;
    double operator+() const;
};

template <typename T>
void Vec<T>::print() const
{
    std::cout << get_name() << "(" << get_x() << "," << get_y() << "," << get_z() << ")\n";
}

template <typename U>
std::string Vec<U>::get_n() const
{
    return get_name();
}

template <typename V>
double Vec<V>::length() const
{
    double le;
    le = std::sqrt(std::pow(get_x(), 2) + std::pow(get_y(), 2) + std::pow(get_z(), 2));
    return le;
}

template <typename T, typename U>
double inner_product(const Vec<T> &a, const Vec<U> &b)
{
    double in;
    in = a.get_x() * b.get_x() + a.get_y() * b.get_y() + a.get_z() * b.get_z();
    return in;
}

template <typename T, typename U>
void comp_print(const Vec<T> &a, const Vec<U> &b)
{
    if (a.length() > b.length())
        std::cout << a.get_n() << " is larget than " << b.get_n() << "\n";
    else if (b.length() > a.length())
        std::cout << b.get_n() << " is larget than " << a.get_n() << "\n";
    else
        std::cout << a.get_n() << " is equal to " << b.get_n() << "\n";
}

template <typename T, typename U>
Vec<double> operator+(const Vec<T> &a, const Vec<U> &b)
{
    return Vec{"newvec", a.get_x() + b.get_x(), a.get_y() + b.get_y(), a.get_z() + b.get_z()};
}
