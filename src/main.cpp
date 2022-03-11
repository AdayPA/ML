#include "perceptron.cpp"
#include "dataset.cpp"
#include "neuralnetwork.cpp"

#include <fstream>

int main (void) {
  Neuron neuron(3,0.5);
  Dataset dataset("../dataset/or");
  Tensor tensor = dataset.GetTensor();
  ANN network(neuron,tensor);
  network.TrainANN(9);
  network.Test({-1,-1,-1});
  network.Test({2,2,2});
  network.Test({2,3,3});
  network.Test({0.1,0.1,0.1});
  return 0;
}