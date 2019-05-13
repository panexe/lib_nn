#ifndef LAYER_H
#define LAYER_H

#include "matrix.h"
#include "activation.h"


class Layer
{
    unsigned int num_nodes;

    Matrix nodes;
    Matrix weights;
    Matrix bias;

    ACTIVATION activation;



public:
    Layer(unsigned int num_nodes,ACTIVATION activation);

    void init(unsigned int nodes_next_layer);
    void activate();


    Matrix getNodes() const;
    void setNodes(const Matrix &value);
};

#endif // LAYER_H
