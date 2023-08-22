#include <vector>
#include <random>
#include <time.h> 
#include <iostream> // To output results to console
#include "pbPlots.hpp"
#include "supportLib.hpp"

double randZeroToOne();
void display(std::vector<double> t);

#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
class NeuralNetwork {
public:
    int inputs, output_nb;
    float learning_rate = 0.001;
    std::vector<std::vector<std::vector<double>>> weights;
    std::vector<std::vector<double>> bias;
    std::vector<std::vector<double>> prev_outputs;
    void initialize_network();
    NeuralNetwork(int inputCount, int outputCount, std::vector<int> hiddenLayers);
    std::vector<double> forward(std::vector<double> X);
    void backward(std::vector<double> data, std::vector<double> output, std::vector<double> intended);
    std::vector<double> softmax(std::vector<double> X);
    std::vector<double> forward_layer(std::vector<double> X, std::vector<std::vector<double>> w, std::vector<double> b);
    double activation(double x);
    void display_network();
    void train(std::vector<std::vector<double>> data, std::vector<std::vector<double>> intended, int itterations);
};
#endif