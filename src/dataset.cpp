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
}

{{{0,1,1},1}, {{0,0,0},0}}


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

#endif