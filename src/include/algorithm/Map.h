//
// Created by Xiaoxing Ye on 08/05/2017.
//

#ifndef CUHKSZ_ALGORITHM_MAP
#define CUHKSZ_ALGORITHM_MAP

#include <vector>
namespace cuhksz {
template<typename Container, typename Func>
std::vector<typename std::result_of<Func(typename Container::value_type &)>::type> map(Container &cont, Func func) {
  std::vector<typename
              std::result_of<Func(typename Container::value_type &)>::type> ret;
  ret.reserve(cont.size());
  for (auto &v : cont) {
    ret.push_back(func(v));
  }
  return ret;
}

}
#endif //CUHKSZ_ALGORITHM_MAP
