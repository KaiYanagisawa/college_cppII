#include <random>
class ExpDist
{
    std::random_device seed;
    std::mt19937 engine;
    std::exponential_distribution<double> edist;
    double unit;

public:
    ExpDist(double lambda, double u = 1.0)
        : seed{}, engine{seed()}, edist{lambda}, unit{u} {}
    auto get() { return edist(engine); }
};