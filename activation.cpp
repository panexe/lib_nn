#include "activation.h"
#include <iostream>

Activation::Activation()
{


}

Activation::FNP Activation::func(ACTIVATION x)
{
    switch (x){
    case ACTIVATION::sigmoid:
        return sigmoid;
    case ACTIVATION::relu:
        return relu;
    case ACTIVATION::tan_h:
        return tan_h;
    }
    std::cerr << "DEFAULT ACTIVATION";
    return sigmoid;
}

Activation::FNP Activation::deriv(ACTIVATION x)
{
    switch (x){
    case ACTIVATION::sigmoid:
        return sigmoid_d;
    case ACTIVATION::relu:
        return relu_d;
    case ACTIVATION::tan_h:
        return tan_h_d;
    }
    std::cerr << "DEFAULT ACTIVATION";
    return sigmoid_d;
}

double Activation::sigmoid(double x)
{
    return 1 / (1 + std::exp(-x));
}

double Activation::sigmoid_d(double x)
{
    return 1 * (1-x);
}

double Activation::tan_h(double x)
{
    return tanh(x);
}

double Activation::tan_h_d(double x)
{
    return 1 - (x*x);
}

double Activation::relu(double x)
{
    if(x <= 0){
        return 0.0;
    }
    return x;
}

double Activation::relu_d(double x)
{
    if(x <= 0){
        return 0.0;
    }
    return 1;
}

Matrix Activation::softmax(const Matrix &x)
{
    Matrix exps = Matrix::map(x,exp);
    return exps / Matrix::sum(exps,0).toVector()[0];
}

double Activation::exp(const double &x)
{
    return std::exp(x);
}




Matrix Activation::softmax_d(const Matrix &x)
{
    return Matrix::hadamard(x,1-x);
}


