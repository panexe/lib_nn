#ifndef LAYER_H
#define LAYER_H

#include "matrix.h"
#include "activation.h"


enum LAYERTYPE{
    Dense
};

class Layer
{
protected:
    unsigned int num_nodes;

    Matrix nodes;
    Matrix weights;
    Matrix bias;

    ACTIVATION activation;


    const LAYERTYPE type;

    Layer *inputLayer;
    Layer *outputLayer;



public:
    Layer(unsigned int num_nodes,ACTIVATION activation = ACTIVATION::sigmoid,LAYERTYPE type = LAYERTYPE::Dense);
    virtual ~Layer();

    virtual void init() = 0;
    virtual Matrix calc_output();

    void activate();
    virtual Matrix getDeriv();


    Matrix getNodes() const;
    void setNodes(const Matrix &value);



    unsigned int getNum_nodes() const;

    virtual Layer *getInputLayer() const;
    virtual void setInputLayer(Layer *value);
    virtual Layer *getOutputLayer() const;
    virtual void setOutputLayer(Layer *value);
    virtual Matrix getBias() const;
    virtual void setBias(const Matrix &value);
    Matrix getWeights() const;
    void setWeights(const Matrix &value);
};

#endif // LAYER_H
