#include "denselayer.h"
#include "iostream"

Layer *DenseLayer::getInputLayer() const
{
    return inputLayer;
}

void DenseLayer::setInputLayer(Layer *value)
{
    inputLayer = value;
}

Layer *DenseLayer::getOutputLayer() const
{
    return outputLayer;
}

void DenseLayer::setOutputLayer(Layer *value)
{
    outputLayer = value;
}

Matrix DenseLayer::getBias() const
{
    return bias;
}

void DenseLayer::setBias(const Matrix &value)
{
    bias = value;
}

DenseLayer::DenseLayer(unsigned int num_nodes_, ACTIVATION activation_) : Layer (num_nodes_,activation_,LAYERTYPE::Dense)
{

}

DenseLayer::~DenseLayer()
{

}

void DenseLayer::init()
{
    if(outputLayer == nullptr){
        std::cerr << "No Output is set \n";
        return;
    }
    if(inputLayer == nullptr){
        std::cerr << "No Input is set \n";
        return;
    }

    this->weights = Matrix(outputLayer->getNum_nodes(),this->num_nodes);
    this->weights.randomize(-1,1);

    this->bias = Matrix(outputLayer->getNum_nodes(),1);
    this->bias.setValues(1);

}

Matrix DenseLayer::calc_output()
{
    Matrix ret = this->weights * this->nodes;
    ret += this->bias;
    return ret;
}

Matrix DenseLayer::getDeriv()
{
    Matrix ret(this->nodes);
    ret.map(Activation::deriv(this->activation));
    return ret;
}

