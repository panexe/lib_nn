#include <iostream>
#include "neuralnetwork.h"

using namespace std;

int main()
{
    /*
    Matrix mat1(4,4);
    mat1.randomize(-10,10);
    Matrix mat2(mat1);

    mat1 = Matrix::hadamard(mat1,1-mat1);
    mat2 = Matrix::map(mat2,NeuralNetwork::sigmoid_d);

    mat1.print();
    mat2.print();
    return 0;
    */

    std::vector<double> vals0{0,0};
    std::vector<double> vals1{0,1};
    std::vector<double> vals2{1,0};
    std::vector<double> vals3{1,1};
    std::vector<double> result0{0};
    std::vector<double> result1{1};

    NeuralNetwork nn(2);
    nn.addLayer(3,ACTIVATION::tan_h);
    nn.compile(1,0.1);

    Matrix
    res =nn.feedForward(Matrix::fromVector(vals0));
    res.print();
    res =nn.feedForward(Matrix::fromVector(vals1));
    res.print();
    res =nn.feedForward(Matrix::fromVector(vals2));
    res.print();
    res =nn.feedForward(Matrix::fromVector(vals3));
    res.print();

    for(int i = 0; i < 10000;i++){
        nn.bp(Matrix::fromVector(vals0),Matrix::fromVector(result0));
        nn.bp(Matrix::fromVector(vals1),Matrix::fromVector(result1));
        nn.bp(Matrix::fromVector(vals2),Matrix::fromVector(result1));
        nn.bp(Matrix::fromVector(vals3),Matrix::fromVector(result0));

    }
    res =nn.feedForward(Matrix::fromVector(vals0));
    res.print();
    res =nn.feedForward(Matrix::fromVector(vals1));
    res.print();
    res =nn.feedForward(Matrix::fromVector(vals2));
    res.print();
    res =nn.feedForward(Matrix::fromVector(vals3));
    res.print();


    return 0;
}
