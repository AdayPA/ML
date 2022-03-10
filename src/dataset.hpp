#ifndef DATASET_HPP_
#define DATASET_HPP_

#include <string>

struct Tensor {
  std::vector<std::vector<float>> input_;
  std::vector<float> output_;
};

class Dataset {
  public:
    Dataset();
    Dataset(std::string);
    inline Tensor GetTensor (void) { return tensor_; };
    ~Dataset();

  private:
    Tensor tensor_;
    std::string inputFile_;
    inline void Set_inputFile(const std::string& filename) { inputFile_ = filename; };
    inline std::string& Get_inputFile (void) { return inputFile_; };
    std::string Get_line (const std::string&, const int&);
    int Count_lines (const std::string);
    std::vector<std::string> Split (std::string, std::string);

};

#endif
