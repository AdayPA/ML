#include "perceptron.cpp"


int main (void) {
  std::vector<float> input;
  input.assign({1, 0, 1, 0, 1});

  Neuron A(5,1.5);
  A.SetInput(input);
  A.PrintValues();






  return 0;
}