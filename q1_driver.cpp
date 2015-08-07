// Copyright [2015] <Brian Mc George>

#include <iostream>
#include <vector>
#include "./find_s.h"
#include "./file_controller.h"
int main(int argc, const char * argv[]) {
  std::vector<std::string> objective = {"Sunny", "Warm", "?", "?", "?", "?"};
  mcgbri004::FindS find(objective.size() + 1);
  std::vector<std::vector<std::string> > attributes = {{"Sunny", "Cloudy", "Rainy"}, {"Warm", "Cold"}, {"Normal", "High"}, {"Strong", "Weak"}, {"Warm", "Cool"}, {"Same", "Change"}};
  std::vector<std::vector<std::string> > training_data = find.generate_training_data(objective, attributes);
  std::cout << training_data.size() << std::endl;
  for(unsigned int i = 0; i < training_data.size(); ++i) {
    for(unsigned int g = 0; g < training_data[i].size(); ++g) {
      if(g + 1 < training_data[i].size()) {
        std::cout << training_data[i][g] << ", ";
      }
      else {
        std::cout << training_data[i][g];
      }
    }
    std::cout << std::endl;
  }
  mcgbri004::save_to_file("training_data.txt", training_data);
  return 0;
}
