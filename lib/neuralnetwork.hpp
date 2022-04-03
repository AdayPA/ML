#ifndef ANN_HPP_
#define ANN_HPP_

#include "dataset.hpp"
#include "perceptron.hpp"
#include "tensor.hpp"

class ANN {
  public:

    ANN(Neuron, Tensor);
    ANN(int, float, std::vector<int>, Tensor); //Nº of inputs, threshold, layers
    ~ANN();
    void TrainNeuron(int);
    void TrainANN(int);
    void Test(std::vector<float>);

  private:

    Neuron neuron_;
    Tensor tensor_;
    std::vector<std::vector<Neuron*>> network_;
    float cost_;

    void Plot(void);
    void CalcCost(void);

};

#endif