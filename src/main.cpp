#include "perceptron.cpp"
#include "dataset.cpp"
#include "neuralnetwork.cpp"

#include <fstream>

int main (void) {
  Neuron neuron(1,1.0);
  Dataset dataset("../dataset/nand");
  Tensor tensor = dataset.GetTensor();
  ANN network(neuron,tensor);
  network.TrainANN(3);
  return 0;
}