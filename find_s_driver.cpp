// Copyright [2015] <Brian Mc George>

#include <iostream>
#include <vector>
#include "./find_s.h"
int main(int argc, const char * argv[]) {
  std::vector<std::vector<std::string> > input;
  const static unsigned int length = 7;
  std::string training_example_1[length] = {"Sunny", "Warm", "Normal", "Strong", "Warm", "Same", "Yes"};
  input.push_back(std::vector<std::string>(std::begin(training_example_1), std::end(training_example_1)));
  std::string training_example_2[length] = {"Sunny", "Warm", "High", "Strong", "Warm", "Same", "Yes"};
  input.push_back(std::vector<std::string>(std::begin(training_example_2), std::end(training_example_2)));
  std::string training_example_3[length] = {"Rainy", "Cold", "High", "Strong", "Warm", "Change", "No"};
  input.push_back(std::vector<std::string>(std::begin(training_example_3), std::end(training_example_3)));
  std::string training_example_4[length] = {"Sunny", "Warm", "High", "Strong", "Cool", "Change", "Yes"};
  input.push_back(std::vector<std::string>(std::begin(training_example_4), std::end(training_example_4)));
  mcgbri004::FindS find_s(length);
  std::vector<std::string> hypothesis = find_s.CalculateHypothesis(input);
  std::cout << "< ";
  for(unsigned int i = 0; i < hypothesis.size() - 1; ++i) {
    if(i + 1 < hypothesis.size() - 1) {
      std::cout << hypothesis[i] << ", ";
    }
    else {
      std::cout << hypothesis[i];
    }
  }
  std::cout << " >" << std::endl;
  return 0;
}
