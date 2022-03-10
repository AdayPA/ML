#include "perceptron.cpp"
#include "dataset.cpp"
#include "neuralnetwork.cpp"

#include <fstream>

int main (void) {
  Neuron neuron(3,0.5);
  Dataset dataset("../dataset/nand");
  Tensor tensor = dataset.GetTensor();
  ANN network(neuron,tensor);
  network.TrainANN(9);

  return 0;
}