//
// Created by Xiaoxing Ye on 19/04/2017.
//

#ifndef CUHKSZ_STRING_FUNCTIONS_H
#define CUHKSZ_STRING_FUNCTIONS_H
#include <exception>
#include <string>
#include <sstream>
namespace cuhksz {
template<typename T>
class stringCast {
 public:
  stringCast(const std::string &from) : m_from(from) {}
  operator T() const {
    std::stringstream strStream(m_from);
    T casted;
    try {
      strStream >> casted;
    }
    catch (std::exception &e) {
      return T(0);
    }
    return casted;
  };

private:
  const std::string &m_from;
};
}
#endif //CUHKSZ_STRING_FUNCTIONS_H
