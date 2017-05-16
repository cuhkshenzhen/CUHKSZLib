//
// Created by Xiaoxing Ye on 08/05/2017.
//

#ifndef CUHKSZ_ALGORITHM_FILTER
#define CUHKSZ_ALGORITHM_FILTER

#include <vector>
namespace cuhksz {
/**
 * Apply a filter function to all elements in a function. All elements with true result will be saved.
 * @tparam Container Container type
 * @tparam Func Function type
 * @param cont Container with all elements
 * @param func Function to be applied
 * @return Elements with true results in std::vector
 */
template <typename Container, typename Func>
std::vector<typename Container::value_type> filterContainer(Container &cont,
                                                            Func func) {
  std::vector<typename Container::value_type> ret;
  ret.reserve(cont.size());
  for (auto &v : cont) {
    if (func(v)) {
      ret.push_back(v);
    }
  }
  return ret;
}
}  // namespace cuhksz
#endif  // CUHKSZ_ALGORITHM_FILTER
