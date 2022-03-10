#ifndef TENSOR_CPP_
#define TENSOR_CPP_

#include <vector>

struct Tensor {
  std::vector<std::vector<float>> input_;
  std::vector<float> output_;
};

#endif