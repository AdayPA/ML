#ifndef DATASET_HPP_
#define DATASET_HPP_

#include "neuralnetwork.hpp"


ANN::ANN(Neuron neuron, Tensor tensor) {
  neuron_ = neuron;
  tensor_ = tensor;
}


ANN::~ANN() {}



#endif