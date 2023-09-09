#include <vector>
#include "neuralNetwork.hpp"
#include "vectors.hpp"
using namespace std;

int main(int argc, char *argv[]) {
    NeuralNetwork network(9,9, std::vector<int>{4});

    std::vector<std::vector<double>> data;
    std::vector<std::vector<double>> results;

    for (int i = 0; i < 9; i++)
    {
        std::vector<double> d(9, 0);
        d[0]=1;
        std::vector<double> r(9, 0);
        r[0]=1;
        data.push_back(d);
        results.push_back(r);
    }
    
    network.train(data, results,1000001);
    
    return 0;
}