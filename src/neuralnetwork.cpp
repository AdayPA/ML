#ifndef ANN_CPP_
#define ANN_CPP_

#include "neuralnetwork.hpp"


ANN::ANN(Neuron neuron, Tensor tensor) {
  neuron_ = neuron;
  tensor_ = tensor;
}


ANN::~ANN() {}

void ANN::TrainANN(int batch) {
  for (int i = 0; i < batch; i++) {
    for (int j = 0; j < tensor_.output_.size(); j++) {
      std::cout << tensor_.output_[j] << std::endl;   
    }
  }
}

#endif