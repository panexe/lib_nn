#ifndef INPUTLAYER_H
#define INPUTLAYER_H

#include "layer.h"

class InputLayer : public Layer
{



public:
    InputLayer(unsigned int num_nodes);
    ~InputLayer() override;

    void init() override;
    Matrix calc_output() override;

    Matrix getDeriv() override;

    void setInput(Layer * input);
    Layer *getOutputLayer() const override;
    void setOutputLayer(Layer *value) override;
    Matrix getBias() const override;
    void setBias(const Matrix &value) override;
};

#endif // INPUTLAYER_H
