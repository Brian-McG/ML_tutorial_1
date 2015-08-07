// Brian Mc George
// MCGBRI004

#ifndef FIND_S_H
#define FIND_S_H
#include <vector>
#include <array>
#include <string>
namespace mcgbri004 {
   class find_s {
      private:
      int const static number_of_constraints = 5;
      public:
      std::vector<std::string> calculate_hypothesis(std::vector<std::string[]> & input);
   };
}
#endif
