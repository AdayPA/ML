#ifndef DATASET_CPP_
#define DATASET_CPP_

#include <string>

class Dataset {
  public:
    Dataset();
    Dataset(std::string, std::string);
    ~Dataset();

  private:
    std::string inputFile_;
    inline void Set_inputFile(const std::string& filename) { inputFile_ = filename; };
    inline std::string& Get_inputFile (void) { return inputFile_; };
    std::string outputFile_;
    inline void Set_outputFile(const std::string& filename) { outputFile_ = filename; };
    inline const std::string& Get_outputFile (void)  { return outputFile_; };
    std::string Get_line (const std::string&, const int&);
    int Count_lines (const std::string);
    std::vector<std::string> Split (std::string, std::string);
    // permissions
    // size for file
    // error type
};

#endif
