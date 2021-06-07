#include <iostream>
#include <random>
#include <queue>
class ExpDist
{
    std::random_device seed;
    std::mt19937 engine;
    std ::exponential_distribution<double> edist;
    double unit;

public:
    ExpDist(double lambda, double u = 1.0)
        : seed{}, engine{seed()}, edist{lambda}, unit{u} {}
    auto get() { return edist(engine) * unit; }
};
int simulate(int num_patient = 100)
{
    ExpDist next_patient{6.0};
    ExpDist clinical_time{7.5};
    double arrival{next_patient.get()};
    std::queue<double> q;
    while (num_patient > 0)
    {
        if (q.empty() || arrival < q.front())
        {
            if (!q.empty())
            {
                q.front() -= arrival;
            }
            q.push(clinical_time.get());
            arrival = next_patient.get();
        }
        else
        {
            arrival -= q.front();
            q.pop();
            --num_patient;
        }
    }
    return q.size();
}
int main(int argc, char *argv[])
{

    const int N{argc > 1 ? std::atoi(argv[1]) : 30};
    double sum{};
    for (int i = 0; i < N; i++)
    {
        auto x{simulate()};
        std::cout << x << " ";
        sum += x;
    }
    std::cout << "\n"
              << sum / N << "\n";

    return 0;
}
