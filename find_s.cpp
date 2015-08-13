//  Copyright [2015] <Brian Mc George>
#include <vector>
#include <string>
#include <iostream>
#include <array>
#include <cstdlib>
#include <unordered_set>
#include <utility>
#include <iterator>
#include <random>
#include "./find_s.h"
namespace mcgbri004 {
  std::vector<std::string> FindS::CalculateHypothesis(const std::vector<std::vector<std::string> > & input) {
    if (input.size() > 0) {
      std::vector<std::string> hypothesis;
      for (unsigned int i = 0; i < number_of_constraints_; ++i) {
        std::string constraint = input[0][i];
        hypothesis.push_back(constraint);
      }
      for (unsigned int i = 1; i < input.size(); ++i) {
        if (input[i][number_of_constraints_-1] == "Yes") {
          for (unsigned int g = 0; g < number_of_constraints_ - 1; ++g) {
            if (hypothesis[g] != input[i][g]) {
              hypothesis[g] = "?";
            }
          }
        }
      }
      return hypothesis;
    } else {
      std::cerr << "No input provided" << std::endl;
    }
    return std::vector<std::string>();
  }

  std::vector<std::vector<std::string> > FindS::GenerateTrainingData(const std::vector<std::string> & objective, const std::vector<std::vector<std::string> > & attributes) {
    std::vector<std::vector<std::string> > training_data;
    std::vector<std::string> current_hypothesis(objective.size() + 1, "");
    std::random_device seeder;
    std::mt19937 engine(seeder());
    int min = 0;
    srand (time(NULL));
    while (!is_equal(current_hypothesis, objective)) {
      for (unsigned int i = 0; i < objective.size(); ++i) {
        if (objective[i] != "?") {
          current_hypothesis[i] = objective[i];
        } else {
          int max = attributes[i].size() - 1;
          std::uniform_int_distribution<int> dist(min, max);
          int random_value = dist(engine);
          current_hypothesis[i] = attributes[i][random_value];
        }
      }
      current_hypothesis[objective.size()] = "Yes";
      bool already_generated = false;
      unsigned int i = 0;
      while (!already_generated && i < training_data.size()) {
        if (current_hypothesis == training_data[i]) {
          already_generated = false;
        }
        ++i;
      }
      if (!already_generated) {
        training_data.push_back(current_hypothesis);
        current_hypothesis = CalculateHypothesis(training_data);
      }
    }
    return training_data;
  }

  bool FindS::is_equal(const std::vector<std::string> & current_hypothesis, const std::vector<std::string> & objective) {
    bool equal = true;
    unsigned int i = 0;
    while(equal && i < objective.size()) {
      if(current_hypothesis[i] != objective[i]) {
        equal = false;
      }
      ++i;
    }
    return equal;
  }
}  // namespace mcgbri004
