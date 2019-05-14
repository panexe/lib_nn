#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "matrix.h"
#include "activation.h"
#include "layer.h"
#include "inputlayer.h"
#include "outputlayer.h"
#include "denselayer.h"

class NeuralNetwork
{

    unsigned int input_size;
    double lr;

    std::vector<Layer*> layers;

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
