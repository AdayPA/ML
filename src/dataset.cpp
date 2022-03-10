#ifndef DATASET_HPP_
#define DATASET_HPP_

#include "dataset.hpp"

#include <fstream>
#include <iostream>
#include <algorithm>

const std::string kFileExt = ".txt";

Dataset::Dataset() {}

Dataset::Dataset(std::string input, std::string output) {
  std::string line;
  std::ifstream myfile;
  myfile.open(input);

  if (!myfile.is_open()) {
    perror("Error open");
    exit(EXIT_FAILURE);
  } while (getline(myfile, line)) {
    std::cout << line << std::endl;
  }

  std::vector<std::string> parse;
  std::cout << "line: "<< line << std::endl;
  parse = Split(line,"-");
  std::cout << parse[0];
  std::cout << parse[1] << std::endl;
  std::vector<std::string> parse2;
  parse2 = Split(parse[0], " ");
  std::cout << "tam parse2: " << parse2.size() << std::endl;
  std::cout << parse2[0];
  std::cout << parse2[1];
  std::cout << parse2[2];
  std::vector<float> trainvect;
  trainvect.push_back(std::stof(parse2[0]));
  trainvect.push_back(std::stof(parse2[1]));
  trainvect.push_back(std::stof(parse2[2]));

  

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