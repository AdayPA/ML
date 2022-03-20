#include "perceptron.cpp"
#include "dataset.cpp"
#include "neuralnetwork.cpp"

#include <fstream>
#include <process.h>

int main (void) {
  
  Neuron neuron(3,0.5);
  Dataset dataset("../dataset/nand");
  Tensor tensor = dataset.GetTensor();
  //ANN network(2,4,{2,2,1},tensor);
  ANN network(neuron,tensor);
  network.TrainNeuron(9);
  network.Test({-2.0,-2.0,-2.0});
  /*network.Test({-1,-1,-1});
  network.Test({2,2,2});
  network.Test({2,3,3});
  network.Test({0.1,0.1,0.1});
  network.Test({2,5,5});*/
  system("start gnuplot -p gnuplot.txt");
  return 0;
}