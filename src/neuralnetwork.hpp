#ifndef ANN_CPP_
#define ANN_CPP_

#include "dataset.hpp"
#include "perceptron.hpp"


class ANN {
  public:

    ANN(Neuron,Tensor);
    ~ANN();

  private:

    Neuron neuron_;
    Tensor tensor_;

};

#endif
