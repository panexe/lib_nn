#include "inputlayer.h"

Layer *InputLayer::getOutputLayer() const
{
    return outputLayer;
}

void InputLayer::setOutputLayer(Layer *value)
{
    outputLayer = value;
}

Matrix InputLayer::getBias() const
{
    return bias;
}

void InputLayer::setBias(const Matrix &value)
{
    bias = value;
}

InputLayer::InputLayer(unsigned int num_nodes_):Layer(num_nodes_)
{

}

InputLayer::~InputLayer()
{

}

void InputLayer::init()
{
    this->weights = Matrix(this->outputLayer->getNum_nodes(),this->num_nodes);
    this->weights.randomize(-1,1);

    this->bias = Matrix(this->outputLayer->getNum_nodes(),1);
    this->bias.setValues(1);

}

Matrix InputLayer::calc_output()
{
    Matrix ret = this->weights * this->nodes;
    ret += this->bias;
    return ret;

}

Matrix InputLayer::getDeriv()
{
    Matrix ret(this->nodes);
    ret.map(Activation::deriv(this->activation));
    return ret;
}


void InputLayer::setInput(Layer *input)
{

}


