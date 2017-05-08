//
// Created by Xiaoxing Ye on 08/05/2017.
//

#ifndef CUHKSZ_ALGORITHM_FILTER
#define CUHKSZ_ALGORITHM_FILTER

#include <vector>
namespace cuhksz {
template<typename Container, typename Func>
std::vector<typename Container::value_type> filter(Container &cont, Func func) {
  std::vector<typename Container::value_type> ret;
  ret.reserve(cont.size());
  for (auto &v : cont) {
    if (func(v)) {
      ret.push_back(v);
    }
  }
  return ret;
}
}
#endif //CUHKSZ_ALGORITHM_FILTER
