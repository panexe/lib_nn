#include "neuralnetwork.h"
#include <cmath>
#include <iostream>


double NeuralNetwork::sigmoid(const double &x)
{
    return 1 / (1 + exp(-x));
}

double NeuralNetwork::sigmoid_d(const double &x)
{
    return x * (1-x);
}



NeuralNetwork::NeuralNetwork(unsigned int input_size_):input_size(input_size_)
{
    this->nodes_amounts.push_back(input_size);
    //this->activations.push_back(ACTIVATION::relu);

}

void NeuralNetwork::addLayer(unsigned int nodes, ACTIVATION activation)
{
    if(nodes != 0){
        this->nodes_amounts.push_back(nodes);
        this->activations.push_back(activation);
        return;
    }
    std::cerr << "0 isnt a valid amount of nodes ";

}

void NeuralNetwork::compile(unsigned int output_size, double lr_, ACTIVATION activation)
{
    this->lr = lr_;

    unsigned int i;
    for(i = 0; i < this->nodes_amounts.size()-1;i++){
        this->layers.push_back(Matrix(nodes_amounts[i],1));
        this->bias.push_back(Matrix(this->nodes_amounts[i+1],1));
        this->weights.push_back(Matrix(nodes_amounts[i+1],nodes_amounts[i]));

        this->bias[i].setValues(1);
        this->weights[i].randomize(-1,1);
    }
    this->layers.push_back(Matrix(nodes_amounts[i],1));
    this->layers.push_back(Matrix(output_size,1));
    this->bias.push_back(Matrix(output_size,1));
    this->bias[i].setValues(1);
    this->weights.push_back(Matrix(output_size,nodes_amounts[i]));
    this->weights[i].randomize(-1,1);
    this->activations.push_back(activation);



}

Matrix NeuralNetwork::feedForward(Matrix input)
{
    // INPUT DIM : rows = this.input_nodes , cols = 1
    this->layers[0] = input;

    // HIDDEN LAYER -----------------------------------------------
    unsigned int i;
    for (i = 1;i < this->layers.size();i++) {
        this->layers[i] = this->weights[i-1] * this->layers[i-1];
        this->layers[i] += this->bias[i-1];
        if(activations[i-1] == softmax){
            this->layers[i] = Activation::softmax(layers[i]);
        }else{
            this->layers[i].map(Activation::func(activations[i-1]));
        }
        //this->layers[i].map(sigmoid);
    }
    return this->layers[i-1];


    /*
    // CALC Z = W * I + BIAS
    this->hidden_nodes = Matrix::multiply(this->weights_input,input);
    // ADD BIAS
    this->hidden_nodes.add(this->bias_hidden);
    // ACTIVATION FUNCTION
    this->hidden_nodes.map(sigmoid);

    // OUTPUT LAYER ------------------------------------------------

    // CALC Z = W * H + B
    this->output_nodes = Matrix::multiply(this->weights_hidden,this->hidden_nodes);
    // ADD BIAS
    this->output_nodes.add(this->bias_output);
    // ACTIVATION FUNCTION
    this->output_nodes.map(sigmoid);


    return output_nodes;
    */

}

void NeuralNetwork::backProp(Matrix x, Matrix y)
{


}

void NeuralNetwork::bp(Matrix x, Matrix y, bool quiet)
{// FEED FORWARD
    this->feedForward(x);

    // CALC ERROR


    unsigned long long i = this->layers.size()-1;

    Matrix error = layers[i] - y;
    if(!quiet)
        std::cout << "Error : " << 0.5*(error.sum().toVector()[0])*(error.sum().toVector()[0]) << std::endl;

    //Matrix deriv = Matrix::hadamard(layers[i],1-this->layers[i]);
    Matrix deriv;
    if(activations[i-1] == ACTIVATION::softmax){
        deriv = Activation::softmax_d(layers[i]);
    }else{
        deriv = Matrix::map(layers[i],Activation::deriv(activations[i-1]));
    }

    Matrix delta = Matrix::hadamard(error,deriv);
    Matrix delta_weight = delta * Matrix::transpose(this->layers[i-1]);

    this->weights[i-1] -= delta_weight * lr;
    this->bias[i-1] -= delta * lr;

    i--;
    for(;i > 0;i--){
        //deriv = Matrix::hadamard(layers[i],1-this->layers[i]);
        deriv = Matrix::map(layers[i],Activation::deriv(activations[i-1]));
        delta = Matrix::transpose(weights[i]) * delta;
        delta.hadamard(deriv);
        delta_weight = delta * Matrix::transpose(this->layers[i-1]);

        this->weights[i-1] -= delta_weight * lr;
        this->bias[i-1] -= delta * lr;

    }
    /*
    // FEED FORWARD
    this->feedForward(x);

    unsigned long long i = this->layers.size()-1;

    // Calc the deriv of the error
    Matrix error = layers[i] - y;

    // sig'(x) = sig(x) * (1-sig(x))
    //Matrix deriv = Matrix::map(layers[i],Activation::deriv(activations[i]));
    Matrix deriv = Matrix::hadamard(this->layers[i],1 - this->layers[i]);
    //Matrix deriv = Matrix::map(layers[i],this->sigmoid_d);

    // delta(l) = error o sig'(x)
    Matrix delta = Matrix::hadamard(error,deriv);
    // delta_w = delta * l(-1)_T
    Matrix delta_weight = delta * Matrix::transpose(this->layers[i-1]);

    // w -= delta_w
    this->weights[i-1] -= delta_weight * lr;
    // bias -= delta
    this->bias[i-1] -= delta * lr;

    i--;
    for(;i > 0;i--){
        // sig'(x) = sig(x) * (1-sig(x))
        //deriv = Matrix::map(layers[i],Activation::deriv(activations[i]));
        deriv = Matrix::hadamard(layers[i],1-this->layers[i]);
        //deriv = Matrix::map(layers[i],this->sigmoid_d);


        // delta = W(l)_T * delta(l-1) o sig'(l)
        delta = Matrix::transpose(weights[i]) * delta;
        delta.hadamard(deriv);
        // delta_w = delta * l(-1)_T
        delta_weight = delta * Matrix::transpose(this->layers[i-1]);

        this->weights[i-1] -= delta_weight * lr;
        this->bias[i-1] -= delta * lr;

    }
    */

}
