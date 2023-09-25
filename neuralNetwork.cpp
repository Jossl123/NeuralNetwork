#include "neuralNetwork.hpp"

double randZeroToOne(){
    return (float)rand() / (float)RAND_MAX;
}

void display(std::vector<double> t){
    for (int i = 0; i < t.size(); i++){
        std::cout << t[i];
        std::cout << ",";
    }
}

void NeuralNetwork::initialize_network(){
    for (int i = 0; i < weights.size(); i++){
        prev_outputs.push_back(std::vector<double>(1, 0));
        for (int j = 0; j < weights[i].size(); j++)
        {
            for (int k = 0; k < weights[i][j].size(); k++)
            {
                double randNum = randZeroToOne() - 0.5; 
                weights[i][j][k] = randNum;
            }
        }
    }
    for (int i = 0; i < bias.size(); i++){
        for (int j = 0; j < bias[i].size(); j++)
        {
            double randNum = randZeroToOne() - 0.5; 
            bias[i][j] = randNum;
        }
    }
}

NeuralNetwork::NeuralNetwork(int inputCount, int outputCount, std::vector<int> hiddenLayers) {
    srand( time(NULL) ); //Randomize seed initialization
    inputs = inputCount;
    output_nb = outputCount;

    // Initialize weights and bias for the hidden layers
    for (int i = 0; i < hiddenLayers.size(); ++i) {
        weights.push_back(std::vector<std::vector<double>>(
            hiddenLayers[i],
            std::vector<double>(i == 0 ? inputCount : hiddenLayers[i - 1])
        ));

        bias.push_back(std::vector<double>(hiddenLayers[i], 0.0f));
    }

    // Initialize weights and bias for the output layer
    weights.push_back(std::vector<std::vector<double>>(
        outputCount,
        std::vector<double>(hiddenLayers.empty() ? inputCount : hiddenLayers.back())
    ));
    bias.push_back(std::vector<double>(outputCount, 0.0f));   
    initialize_network();
}

std::vector<double> NeuralNetwork::forward(std::vector<double> X){
    if (X.size() != inputs){ 
        std::cout << "[ERROR] inputs number are different"; 
        exit(0);
    }
    std::vector<double> current_layer = X;
    for (int i = 0; i < weights.size(); i++){
        current_layer = forward_layer(current_layer, weights[i], bias[i]);
        if (i<weights.size()-1){ 
            for (int j = 0; j < current_layer.size(); j++){
                current_layer[j] = activation(current_layer[j]);
            }
        } 
        prev_outputs[i] = current_layer; 
    }return current_layer;
}

void NeuralNetwork::backward(std::vector<double> data, std::vector<double> output, std::vector<double> output_intended) {
    if (output.size() != output_intended.size()) { 
        std::cerr << "[ERROR] Output and intended vectors have different sizes\n"; 
        exit(1); 
    }
    int m = output.size(); 
    std::vector<std::vector<double>> dz = onedTo2d(subtract(output, output_intended));
    for (int layer_index = weights.size() - 1; layer_index >= 0; layer_index--) { 
        std::vector<std::vector<double>> dw(weights[layer_index].size(), std::vector<double>(weights[layer_index][0].size(), 0.0));
        std::vector<double> db(weights[layer_index].size(), 0.0);
        for (int i = 0; i < m; i++) { 
            for (int j = 0; j < weights[layer_index].size(); j++) { 
                for (int k = 0; k < weights[layer_index][j].size(); k++) {
                    dw[j][k] += dz[i][j] * prev_outputs[layer_index][i] * data[k];
                }
                db[j] += dz[i][j];
            }
        }
        for (int i = 0; i < weights[layer_index].size(); i++) {
            for (int j = 0; j < weights[layer_index][i].size(); j++) {
                weights[layer_index][i][j] -= learning_rate * (dw[i][j] / m);
            }
            bias[layer_index][i] -= learning_rate * (db[i] / m);
        } 
        if (layer_index > 0) {
            std::vector<std::vector<double>> a = transpose(weights[layer_index]); 
            dz = multiply(a, dz);
            for (int i = 0; i < m; i++) { 
                for (int j = 0; j < dz[i].size(); j++) {
                    dz[i][j] *= derive_activation(prev_outputs[layer_index - 1][i]);
                }
            }
        }
    }
}

std::vector<double> NeuralNetwork::softmax(std::vector<double> X) {
    std::vector<double> res; 
    double sum = 0; 
    int size = X.size();
    for (int i = 0; i < size; i++) sum += exp(X[i]);
    for (int i = 0; i < size; i++) res.push_back(exp(X[i]) / sum); 
    return res;
}

std::vector<double> NeuralNetwork::forward_layer(std::vector<double> X, std::vector<std::vector<double>> w, std::vector<double> b){
    std::vector<double> next_layer;
    for (int j = 0; j < w.size(); j++){
        double n = b[j];
        for (int k = 0; k < w[j].size(); k++){
            n += X[j] * w[j][k];
        }
        next_layer.push_back(n);
    }
    return next_layer;
}

double NeuralNetwork::activation(double x){
    // if (x < 0)return 0;
    // return x;
    return 1.0 / (1.0 + exp(-x));
}
double NeuralNetwork::derive_activation(double x){
    // if (x < 0)return 0;
    // return 1;
    return activation(x) * (1 - activation(x));
}


void NeuralNetwork::display_network(){
    std::cout << "weights \n";
    for (int i = 0; i < weights.size(); i++){
        std::cout << "  ";
        std::cout << i;
        std::cout << ":\n";
        for (int j = 0; j < weights[i].size(); j++)
        {
            std::cout << "    ";
            std::cout << j;
            std::cout << "\n";
            for (int k = 0; k < weights[i][j].size(); k++)
            {
                std::cout << "      ";
                std::cout << weights[i][j][k];
                std::cout << "\n";
            }
        }
    }
    std::cout << "bias \n";
    for (int i = 0; i < bias.size(); i++){
        std::cout << "  ";
        std::cout << i;
        std::cout << ":\n";
        for (int j = 0; j < bias[i].size(); j++)
        {
            std::cout << "    ";
            std::cout << bias[i][j];
            std::cout << "\n";
        }
    }
}   

void NeuralNetwork::train(std::vector<std::vector<double>> data, std::vector<std::vector<double>> intended, int itterations){
    if (data.size() != intended.size())exit(1);
    display_network();
    StringReference *errorMessage = CreateStringReferenceLengthValue(0, L' ');
    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();
    std::vector<double> x;
    std::vector<double> y;
    for (int i = 0; i < itterations; i++){
        x.push_back(i);
        if (i %100 == 0){
            std::cout << " :\n";
            std::cout << "    itteration ";
            std::cout << i;
        }
        double cum_error = 0;

        for (int j = 0; j < data.size(); j++)
        {
            std::vector<double> input = data[j];
            std::vector<double> output_intended = intended[j];
            std::vector<double> output = forward(input);
            if (i %100 == 0){
                std::cout << "intput : ";
                display(input);
                std::cout << "output : ";
                display(output);
                std::cout << " vs ";
                display(output_intended);
            }
            backward(input, output, output_intended);

            //partial error calculation for graph
            cum_error+=fabs(output[0] - output_intended[0]);
        }



        y.push_back(cum_error);
    }
    DrawScatterPlot(imageRef, 600, 400, &x, &y, errorMessage);
    std::vector<double> *pngData = ConvertToPNG(imageRef -> image);
    WriteToFile(pngData, "plot.png");
    DeleteImage(imageRef -> image);
    display_network();
}
