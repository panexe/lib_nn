#include "layer.h"

Matrix Layer::getNodes() const
{
    return nodes;
}

void Layer::setNodes(const Matrix &value)
{
    nodes = value;
}

Layer::Layer(unsigned int num_nodes_,ACTIVATION activation_): num_nodes(num_nodes_),activation(activation_)
{

}

void Layer::init(unsigned int nodes_next_layer)
{
    this->weights = Matrix(nodes_next_layer,this->num_nodes);
    this->bias = Matrix(this->num_nodes,1);

}

void Layer::activate()
{
    this->nodes.map(Activation::func(this->activation));
}
