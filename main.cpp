#include <vector>
#include "neuralNetwork.hpp"
#include "vectors.hpp"
using namespace std;

int main(int argc, char *argv[]) {
    NeuralNetwork network(1,1, std::vector<int>{});

    std::vector<std::vector<double>> data;
    std::vector<std::vector<double>> results;

    for (int i = 0; i < 9; i++)
    {
        std::vector<double> d(1, 0);
        d[0]=i;
        std::vector<double> r(1, 0);
        r[0]=i*3;
        data.push_back(d);
        results.push_back(r);
    }
    
    network.train(data, results,1000000);
    
    return 0;
}