//
// Created by Xiaoxing Ye on 19/04/2017.
//

#ifndef CUHKSZ_STRING_FUNCTIONS_H
#define CUHKSZ_STRING_FUNCTIONS_H
namespace cuhksz {
#include <string>
template<typename T>
class stringCast {
 public:
  stringCast(const std::string &from) : m_from(from) {}
  operator T() const;
 private:
  const std::string &m_from;
};
}
#endif //CUHKSZ_STRING_FUNCTIONS_H
