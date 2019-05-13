#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "matrix.h"
#include "activation.h"

class NeuralNetwork
{
    std::vector<unsigned int> nodes_amounts;
    std::vector<ACTIVATION> activations;

    unsigned int input_size;
    double lr;

    Matrix weights_input;
    Matrix bias_input;


    std::vector<Matrix> layers;
    std::vector<Matrix> weights;
    std::vector<Matrix> bias;

    Matrix output_nodes;
    Matrix bias_output;

    static double sigmoid(const double& x);


public:

    static double sigmoid_d(const double& x);

    NeuralNetwork(unsigned int input_size);

    void addLayer(unsigned int nodes, ACTIVATION activation = ACTIVATION::sigmoid);
    void compile(unsigned int output_size, double lr = 0.01, ACTIVATION activation = ACTIVATION::sigmoid);

    Matrix feedForward(Matrix input);
    void backProp(Matrix input,Matrix output);
    void bp(Matrix x,Matrix y, bool quiet = true);

};

#endif // NEURALNETWORK_H
