//
// Created by Xiaoxing Ye on 08/05/2017.
//

#ifndef CUHKSZ_CPP_LIB_MAP_H_H
#define CUHKSZ_CPP_LIB_MAP_H_H
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
#endif //CUHKSZ_CPP_LIB_MAP_H_H
