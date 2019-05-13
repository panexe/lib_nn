#ifndef ACTIVATION_H
#define ACTIVATION_H
#include "cmath"
#include "matrix.h"


enum ACTIVATION{
    sigmoid = 0,
    tan_h = 1,
    relu = 2,
    softmax = 3
};

class Activation
{
    ACTIVATION actv;

    static double sigmoid(double x);
    static double sigmoid_d(double x);

    static double tan_h(double x);
    static double tan_h_d(double x);

    static double relu(double x);
    static double relu_d(double x);

public:
    typedef double (*FNP)(double);
    static FNP func(ACTIVATION x);
    static FNP deriv(ACTIVATION x);




    static double exp(const double& x);

    Activation();
    double (*(*f2)(double))(ACTIVATION a);
    double (*getFunc(void))(ACTIVATION a);
    double deriv(const double& x);

    static Matrix softmax(const Matrix& x);
    static Matrix softmax_d(const Matrix& x);



};

#endif // ACTIVATION_H
