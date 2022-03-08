#include "perceptron.cpp"


int main (void) {
  std::vector<float> x = {0.7, 0.6, 0.5, 0.3, 0.4};
  std::vector<bool> input;
  input.assign({1, 0, 1, 0, 1});

  Neuron A(5,1.5);
  A.SetInput(input);
  A.SumUnit();
  A.PrintValues();
  return 0;
}