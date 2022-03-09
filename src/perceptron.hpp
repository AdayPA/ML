#ifndef PERCEPTRON_HPP_
#define PERCEPTRON_HPP_

#include <vector>

class Neuron {

  public:

  Neuron (int, float);
  ~Neuron ();

  float GetSigma (void);
  void SetInput (std::vector<float>);
  void PrintValues (void);


  private:

    float threshold_;
    float sigma_;
    float bias_;
    float error_;
    float correction_;
    float learning_rate_;
    float desired_output_;
    bool error_arguments_;
    int activation_;
    int size_;
    std::vector<float> input_;
    std::vector<float> weight_;

    float CalcSigma (void);
    bool ActivationFunc (void);
    void CalcError (void);
    void CalcCorrection (void);
    void SetRandom (void);
    void UpdateWeight (void);

};

#endif