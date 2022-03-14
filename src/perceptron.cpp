#ifndef PERCEPTRON_CPP_
#define PERCEPTRON_CPP_

#include <cstdlib>
#include <iostream>
#include <random>
#include <chrono>

#include "perceptron.hpp"

Neuron::Neuron(){}

Neuron::Neuron(int input_size, float input_threshold) {
  bias_ = 0.0;
  sigma_ = 0.0;
  error_ = 0.0;
  learning_rate_ = 0.1;
  error_arguments_ = false;
  size_ = input_size;
  input_.resize(input_size);
  weight_.resize(input_size);
  threshold_ = input_threshold;
  SetRandom();
}

Neuron::~Neuron() {

}

void Neuron::SetInput(std::vector<float> input) {
  if (input.size() == input_.size() && !error_arguments_) {
    for (int i = 0; i < size_; i++) {
      input_[i] = input[i];
    }
  } else {
    printf("Input values does not match with the input size.");
    error_arguments_ = true;
  }
}

void Neuron::SetOutput(float output) {
  desired_output_ = output;
}


void Neuron::CalcSigma(void) {
  if (!error_arguments_) {
    float temp = 0.0;
    for (int i = 0; i < size_; i++) {
      temp += input_[i] * weight_[i];
    }
    sigma_ = temp;
  }
  printf("\nSigma: %f", sigma_);
  //sigma_ += bias_;
}

void Neuron::ActivationFunc (void) {
  if (sigma_ > threshold_) {
    result_ = 1;
  } else {
    result_ = 0;
  };
  printf("\nActivation: %i", result_);
}

void Neuron::CalcError (void) {
  //printf("\nCalculo error: %f - %f",desired_output_, activation_);
  error_ = desired_output_ - result_;
  printf(" =  %f", error_);
}

void Neuron::CalcCorrection (void) {
  correction_ = learning_rate_ * error_;
  printf("\nCorreccion =  %f", correction_);
}

void Neuron::UpdateWeight(void) {
  for (int i = 0; i < size_; i++) {
    weight_[i] +=  (input_[i] * correction_);
  }
   for (int i = 0; i < size_; i++) {
    std::cout << "\nPesos: " << weight_[i] << "";
  }
}

void Neuron::PrintValues(void) {
  for (int i = 0; i < size_; i++) {
    std::cout << "Pesos: " << weight_[i] << "\n";
  }
  printf("Sigma: %f\n", sigma_);
  printf("Desired output: %i\n", desired_output_);
  printf("ActivationFunc: %i\n", result_);
  printf("CalcError: %f\n", error_);
  printf("CalcCorrection: %f\n", correction_);
}

void Neuron::SetRandom(void) {
  if (!error_arguments_) {
    std::mt19937_64 rng;
    // initialize the random number generator with time-dependent seed
    uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32)};
    rng.seed(ss);
    // initialize a uniform distribution between 0 and 1
    std::uniform_real_distribution<double> unif(-1, 1);
    // ready to generate random numbers
    const int nSimulations = 10;
    for (int i = 0; i < size_; i++)
    {
      float currentRandomNumber = unif(rng);
      //weight_[i] = currentRandomNumber;
      weight_[i] = 0;
    }
  }
}

void Neuron::Train(void) {
  CalcSigma();
  ActivationFunc();
  CalcError();    
  CalcCorrection();
}

void Neuron::TrainNeuron(void) {
  CalcSigma();
  ActivationFunc();
  CalcError();    
  CalcCorrection();
  UpdateWeight();
}

int Neuron::Test(void) {
  CalcSigma();
  ActivationFunc();
  return result_;
}

#endif