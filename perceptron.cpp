#ifndef PERCEPTRON_CPP_
#define PERCEPTRON_CPP_

#include <cstdlib>
#include <iostream>
#include <random>
#include <chrono>

#include "perceptron.hpp"



Neuron::Neuron(int input_size, float input_threshold) {
  size_ = input_size;
  input_.resize(input_size);
  weight_.resize(input_size);
  threshold_ = input_threshold;
  SetRandom();
}

Neuron::Neuron(int input_size, float input_threshold, std::vector<float> input_weight) {

}

Neuron::~Neuron() {

}

float Neuron::SumUnit(void) {}

void Neuron::SetRandom(void) {

  std::mt19937_64 rng;
  // initialize the random number generator with time-dependent seed
  uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  std::seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32)};
  rng.seed(ss);
  // initialize a uniform distribution between 0 and 1
  std::uniform_real_distribution<double> unif(0, 1);
  // ready to generate random numbers
  const int nSimulations = 10;
  for (int i = 0; i < size_; i++)
  {
    float currentRandomNumber = unif(rng);
    weight_[i] = currentRandomNumber;
  }

}


#endif