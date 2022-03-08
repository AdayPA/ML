#ifndef PERCEPTRON_HPP_
#define PERCEPTRON_HPP_

#include <vector>

class Neuron {

  public:
  Neuron(int, float);
  Neuron(int, float, std::vector<float>);
  ~Neuron();

  void SetInput(std::vector<bool> );
  float SumUnit (void);
  void PrintValues (void);

  private:
  bool error_;
  int size_;
  std::vector<bool> input_;
  std::vector<float> weight_;
  float threshold_;
  float sigma_;

  void SetRandom (void);

};

#endif