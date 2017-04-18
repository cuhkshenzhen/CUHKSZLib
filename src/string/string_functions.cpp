//
// Created by Xiaoxing Ye on 19/04/2017.
//

#include <sstream>
#include "string/string_functions.h"
namespace cuhksz {
template<typename T>
stringCast<T>::operator T() const {
  std::stringstream strStream(m_from);
  T ret;
  try {
    strStream >> ret;
  }
  catch (std::exception &e) {
    return T(0);
  }
  return ret;
};
}
