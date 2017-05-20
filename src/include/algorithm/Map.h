//
// Created by Xiaoxing Ye on 08/05/2017.
//

#ifndef CUHKSZ_ALGORITHM_MAP
#define CUHKSZ_ALGORITHM_MAP

#include <vector>
namespace cuhksz {
/**
 * Map all elements in a container to a custom function. Results will be saved
 * to a vector.
 * @tparam Container Container type
 * @tparam Func Function type
 * @param cont Container that saving all elements
 * @param func Function to be applied to elements
 * @return std::vector in result type with results saved.
 */
template <typename Container, typename Func>
std::vector<
    typename std::result_of<Func(typename Container::value_type &)>::type>
mapAll(Container &cont, Func func) {
  std::vector<
      typename std::result_of<Func(typename Container::value_type &)>::type>
      ret;
  ret.reserve(cont.size());
  for (auto &v : cont) {
    ret.push_back(func(v));
  }
  return ret;
}

}  // namespace cuhksz
#endif  // CUHKSZ_ALGORITHM_MAP
