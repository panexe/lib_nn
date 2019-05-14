#ifndef DENSELAYER_H
#define DENSELAYER_H

#include "layer.h"


class DenseLayer : public Layer
{



public:
    DenseLayer(unsigned int num_nodes, ACTIVATION activation);
    ~DenseLayer() override;

    void init() override;
    Matrix calc_output() override;

    Matrix getDeriv() override;



    Layer *getInputLayer() const override;
    void setInputLayer(Layer *value) override;
    Layer *getOutputLayer() const override;
    void setOutputLayer(Layer *value) override;
    Matrix getBias() const override;
    void setBias(const Matrix &value) override;
};

#endif // DENSELAYER_H
