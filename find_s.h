// Copyright [2015] <Brian Mc George>
#ifndef FIND_S_H_
#define FIND_S_H_
#include <vector>
#include <array>
#include <string>
namespace mcgbri004 {
class FindS {
 private:
    unsigned int number_of_constraints_;
    bool is_equal(const std::vector<std::string> & current_hypothesis, const std::vector<std::string> & objective);
 public:
    FindS(void) {}
    explicit FindS(unsigned int num_constraints) {
      number_of_constraints_ = num_constraints;
    }
    std::vector<std::vector<std::string> > generate_training_data(const std::vector<std::string> & objective, const std::vector<std::vector<std::string> > & attributes);
    std::vector<std::string> calculate_hypothesis(const std::vector<std::vector<std::string> > & input);
};
}  // namespace mcgbri004
#endif  // FIND_S_H_
