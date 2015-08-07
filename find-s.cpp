// Brian Mc George
// MCGBRI004
// 07-08-2015
#include <vector>
#include <string>
#include <iostream>
#include <array>
#include "find-s.h"
namespace mcgbri004 {
   std::vector<std::string> find_s::calculate_hypothesis(std::vector<std::string[]> & input) {
      if(true) {
         std::vector<std::string> hypothesis;
         for(int i = 0; i < number_of_constraints; ++i) {
            std::string test = input[0][i];
            hypothesis.push_back(test);
         }
         for(int i = 0; i < input.size(); ++i) {
            for(int g = 0; g < number_of_constraints; ++g) {
               if(hypothesis[g] != input[i][g]) {
                  hypothesis[i] = nullptr;
               }
            }
         }
         return hypothesis;
      }
      else {
         std::cerr << "No input provided" << std::endl;
      }
      return std::vector<std::string>();
   }
}
