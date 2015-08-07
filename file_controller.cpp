// Copyright [2015] <Brian Mc George>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "./file_controller.h"
namespace mcgbri004 {
  bool save_to_file(const std::string & file_name, const std::vector<std::vector<std::string> > & training_data) {
    std::fstream file_stream;
    file_stream.open(file_name, std::ios_base::out | std::ios_base::in);
    bool can_change;
    if (file_stream.is_open()) {
      std::string response;
      std::cout << "File already exists, do you wish to override the file? (Y / N)" << std::endl;
      bool is_response = false;    
      while (!is_response) {
        std::getline(std::cin, response);
        if (response.compare("Y") == 0 || response.compare("y") == 0) {
          is_response = true;
          can_change = true;
        } else if (response.compare("N") == 0 || response.compare("n") == 0) {
          is_response = true;
          can_change = false;
        } else {
          std::cerr << "Invalid response provided" <<std::endl;
        }
      }
    }
    file_stream.close();
    std::fstream out_stream;
    out_stream.open(file_name, std::ios_base::out | std::ios_base::trunc);
    if (out_stream.fail()) {
      std::cerr << "Failed to write data to file, " << file_name << std::endl;
      return false;
    }
    out_stream << "Number of examples: " << training_data.size() << std::endl;
    for(unsigned int i = 0; i < training_data.size(); ++i) {
      for(unsigned int g = 0; g < training_data[i].size(); ++g) {
        if(g + 1 < training_data[i].size()) {
          out_stream << training_data[i][g] << ", ";
        }
        else {
          out_stream << training_data[i][g];
        }
      }
      if(i + 1 < training_data.size()) {
        out_stream << std::endl;
      }
    }
    if (out_stream.fail()) {
      std::cerr << "Failed to write data to file, " << file_name << std::endl;
      return false;
    }
    if(can_change) {
      std::cout << "Succesfully wrote statistics data to " << file_name << std::endl;
    }
    return true;
  }
}  // namespace mcgbri004
