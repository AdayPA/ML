#ifndef DATASET_HPP_
#define DATASET_HPP_

#include "dataset.hpp"

#include <fstream>
#include <iostream>
#include <algorithm>

const std::string kDelimiter = "-";
const std::string kSpace = " ";

Dataset::Dataset() {}

Dataset::Dataset(std::string input) {
  std::string line;
  std::ifstream myfile;
  myfile.open(input);

  if (!myfile.is_open()) {
    perror("Error open");
    exit(EXIT_FAILURE);
  }
  while (getline(myfile, line)) {
    std::vector<std::string> parse;
    parse = Split(line, kDelimiter);
    tensor_.output_.push_back(std::stof(parse[1]));
    std::vector<std::string> parse_tensor;
    parse_tensor = Split(parse[0], kSpace);
    std::vector<float> temp;
    for (int i = 0; i < parse_tensor.size(); i++) {
      temp.push_back(std::stof(parse_tensor[i]));
    }
    tensor_.input_.push_back(temp);
  }

  std::cout << tensor_.input_[1][1];

}


Dataset::~Dataset() {}

std::string Dataset::Get_line(const std::string& filename, const int& line_number) {
  std::ifstream inputfile(filename);
  auto temp(1);
  std::string line;
  while( (!(inputfile.eof())) && (temp < line_number)) {
    std::getline(inputfile, line);
    ++temp;
  } 
  std::getline(inputfile, line);
  return line;
}

int Dataset::Count_lines(const std::string file) {
  int lines = 0;
  std::ifstream file_to_count(file);
  std::string unused;
  while (std::getline(file_to_count, unused)) {
    ++lines;
  }
  return lines;
}

std::vector<std::string> Dataset::Split (std::string str, std::string delim) {
  /// @brief this func split in 2 the string and store them in vector, 
  //         depending of the char
  std::vector<std::string> tokens;
  size_t prev = 0, pos = 0;
  do {
    pos = str.find(delim, prev);
    if (pos == std::string::npos) pos = str.length();
    std::string token = str.substr(prev, pos-prev);
    if (!token.empty()) tokens.push_back(token);
    prev = pos + delim.length();
  }
  while (pos < str.length() && prev < str.length());
  return tokens;
}

#endif