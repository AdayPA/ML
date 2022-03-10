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

    printf("\nIteracion: %i\n", i+1);
    for (int j = 0; j < tensor_.output_.size(); j++) {
      printf("\nLinea: %i\n", j+1);
      neuron_.SetInput(tensor_.input_[j]);  
      neuron_.SetOutput(tensor_.output_[j]);
      neuron_.Train();
    }

  }

}

#endif