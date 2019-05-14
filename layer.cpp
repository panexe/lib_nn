#include "layer.h"
#include "iostream"

Matrix Layer::getNodes() const
{
    return nodes;
}

void Layer::setNodes(const Matrix &value)
{
    nodes = value;
}

unsigned int Layer::getNum_nodes() const
{
    return num_nodes;
}

Layer *Layer::getInputLayer() const
{
    return inputLayer;
}

void Layer::setInputLayer(Layer *value)
{
    inputLayer = value;
}

Layer *Layer::getOutputLayer() const
{
    return outputLayer;
}

void Layer::setOutputLayer(Layer *value)
{
    outputLayer = value;
}

Matrix Layer::getBias() const
{
    return bias;
}

void Layer::setBias(const Matrix &value)
{
    bias = value;
}

Matrix Layer::getWeights() const
{
    return weights;
}

void Layer::setWeights(const Matrix &value)
{
    weights = value;
}

Layer::Layer(unsigned int num_nodes_,ACTIVATION activation_, LAYERTYPE type_): num_nodes(num_nodes_),activation(activation_), type(type_)
{


}

Layer::~Layer()
{

}

Matrix Layer::calc_output()
{

}

void Layer::init()
{

}


void Layer::activate()
{
    this->nodes.map(Activation::func(this->activation));
}

Matrix Layer::getDeriv()
{

}

