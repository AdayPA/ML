#ifndef ANN_CPP_
#define ANN_CPP_

#include "neuralnetwork.hpp"

ANN::ANN(Neuron neuron, Tensor tensor) {
  neuron_ = neuron;
  tensor_ = tensor;
}

ANN::ANN(int input, float threshold, std::vector<int> network, Tensor tensor) {
  int inputs_neuron = 0;
  int temp_input_neuron = input;
  tensor_ = tensor;
  for (int i = 0; i < network.size(); i++) {
    std::vector<Neuron*> temp_layer;
    for (int j = 0; j < network[i]; j++) {
      temp_layer.push_back(new Neuron(temp_input_neuron,threshold));
      inputs_neuron++;
    }
    temp_input_neuron = inputs_neuron;
    inputs_neuron = 0;
    network_.push_back(temp_layer);
  }
  //int a = network_[0][0]->GetSize();
  //std::cout << a;
  //std::cout << network_.at(3).size() << std::endl;
  //std::cout << network_.size();
}



ANN::~ANN() {}

void ANN::TrainANN(int batch) {
  std::vector<float> temp_results;
  std::vector<float> temp_next_results;
  int stage;
  for (int i = 0; i < network_.at(0).size(); i++) {
    network_.at(0).at(i)->SetInput(tensor_.input_[i]);
    network_.at(0).at(i)->Train();
    temp_results.push_back(network_.at(0).at(i)->GetSigma());
  }
  for (int i = 1; i < network_.size(); i++) {
    for (int j = 0; j < network_.at(i).size(); j++) {
      network_.at(i).at(j)->SetInput(temp_results);
      network_.at(i).at(j)->Train();
      temp_next_results.push_back(network_.at(i).at(j)->GetSigma());
    }
    temp_results = temp_next_results;
    temp_next_results.clear();
  }

}

void ANN::TrainNeuron(int batch) {
  for (int i = 0; i < batch; i++) {
    printf("\nIteracion: %i\n", i+1);
    for (int j = 0; j < tensor_.output_.size(); j++) {
      printf("\nLinea: %i\n", j+1);
      neuron_.SetInput(tensor_.input_[j]);  
      neuron_.SetOutput(tensor_.output_[j]);
      neuron_.TrainNeuron();
    }
  }
}

void ANN::Test(std::vector<float> input) {
  neuron_.SetInput(input);
  int temp = neuron_.Test();
  std::cout << "\nsalida del test: " << temp ;
}

void ANN::Plot(void) {}

#endif