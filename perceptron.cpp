#ifndef PERCEPTRON_CPP_
#define PERCEPTRON_CPP_

#include <cstdlib>
#include <iostream>
#include <random>
#include <chrono>

#include "perceptron.hpp"

Neuron::Neuron(int input_size, float input_threshold) {
  sigma_ = 0.0;
  error_ = false;
  size_ = input_size;
  input_.resize(input_size);
  weight_.resize(input_size);
  threshold_ = input_threshold;
  SetRandom();
}

Neuron::Neuron(int input_size, float input_threshold, std::vector<float> input_weight) {
  sigma_ = 0.0;
  size_ = input_size;
  input_.resize(input_size);
  weight_.resize(input_size);
  threshold_ = input_threshold;
  if (input_size == input_weight.size()) {
    weight_ = input_weight;
  } else {
    printf("Input weight does not match with the input size.");
    error_ = true;
  }
}

Neuron::~Neuron() {

}

void Neuron::SetInput(std::vector<bool> input) {
  if (input.size() == input_.size() && !error_) {
    for (int i = 0; i < size_; i++) {
      input_[i] = input[i];
    }
  } else {
    printf("Input values does not match with the input size.");
    error_ = true;
  }
}

float Neuron::SumUnit(void) {
  if (!error_) {
    for (int i = 0; i < size_; i++) {
      sigma_ += input_[i] * weight_[i];
    }
  }
}

void Neuron::PrintValues(void) {
  for (int i = 0; i < size_; i++) {
    std::cout << input_[i] << " " << weight_[i] << "\n";
  }
  printf("Total: %f", sigma_);
}

void Neuron::SetRandom(void) {
  if (!error_) {
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
      weight_[i] = currentRandomNumber;
    }
  }
}


#endif