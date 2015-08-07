// Copyright [2015] <Brian Mc George>

#ifndef FILE_CONTROLLER_H_
#define FILE_CONTROLLER_H_
#include <string>
#include <vector>

namespace mcgbri004 {
  bool save_to_file(const std::string & filename, const std::vector<std::vector<std::string> > & training_data);
}  // namespace mcgbri004
#endif  // FILE_CONTROLLER_H_
