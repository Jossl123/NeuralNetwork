#include <vector>
#include "neuralNetwork.hpp"
using namespace std;

int main(int argc, char *argv[]) {
    NeuralNetwork network(1, 1, std::vector<int>(0));

    std::vector<std::vector<double>> data;
    std::vector<std::vector<double>> results;

    for (int i = 0; i < 4; i++)
    {
        std::vector<double> d(1, i);
        std::vector<double> r(1, i*3 + 1);
        data.push_back(d);
        results.push_back(r);
    }

    network.train(data, results, 100);
    return 0;
}