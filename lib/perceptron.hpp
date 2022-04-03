#ifndef PERCEPTRON_HPP_
#define PERCEPTRON_HPP_

#include <vector>

class Neuron {

  public:

    Neuron();
    Neuron (int, float);
    ~Neuron ();

    //inline float GetSigma (void) { return sigma_; }
    void SetInput (std::vector<float>);
    void SetOutput (float);
    void PrintValues (void);
    void TrainNeuron(void);
    void Train(void);
    int Test(void);
    inline float GetSigma(void) { return sigma_;};
    inline float GetResult(void) { return result_;};
  private:

    float threshold_;
    float sigma_;
    float bias_;
    float error_;
    float correction_;
    float learning_rate_;
    float desired_output_;
    float result_;
    bool error_arguments_;
    int size_;
    std::vector<float> input_;
    std::vector<float> weight_;

    void ActivationFunc (void);
    void CalcSigma (void);
    void CalcError (void);
    void CalcCorrection (void);
    void SetRandom (void);
    void UpdateWeight (void);

};

#endif