#ifndef CUHKSZ_ALGORITHM_ZIP
#define CUHKSZ_ALGORITHM_ZIP
#include <iterator>
#include <vector>
namespace cuhksz {

template<typename T>
class Zip {
 public:
  typedef std::vector<T> container;

  template<typename... Args>
  Zip(const T &head, const Args &... args):
      items(head.size()), min_(head.size()) {
    zip_(head, args...);
  }
  inline operator container() const {
    return items;
  }

  inline container operator()() const {
    return items;
  }

 private:

  template<typename... Args>
  void zip_(const T &head, const Args &... tail) {
    if (head.size() < min_) min_ = head.size();

    for (std::size_t i = 0; i < min_; ++i) {
      typename T::const_iterator itr = head.begin();
      std::advance(itr, i);
      items[i].push_back(*itr);
    }

    return zip_(tail...);
  }

  void zip_() {
    items.resize(min_);
  }

  container items;

  std::size_t min_;

};

/**
 * Zip two or more containers together
 *
 * Example:
  ```
  std::vector<int> a = {1, 2, 3, 4};
  std::vector<int> b = {5, 6, 7, 8};
  std::vector<int> c = {9, 10, 11};
  std::vector<std::vector<int>> result = {{1, 5, 9}, {2, 6, 10}, {3, 7, 11}};
  auto origin = cuhksz::zip(a, b, c);
  // origin == result
  ```
 * @tparam T Type of first container
 * @tparam Args Types of remaining containers
 * @param head First container
 * @param tail Remaining containers
 * @return std::vector<T>
 */
template<typename T, typename... Args>
typename Zip<T>::container zip(const T &head, const Args &... tail) {
  return Zip<T>(head, tail...);
}
}

#endif //CUHKSZ_ALGORITHM_ZIP
