//
// Created by Xiaoxing Ye on 18/04/2017.
//

#include <vector>
#include "zip/zip_functions.h"
namespace cuhksz {
template<typename T, typename... Args>
Zip<T>::Zip(const T &head, const Args &... args):
    items(head.size()), min_(head.size()) { // member initialization
  zip_(head, args...);
}

template<typename T, typename... Args>
void Zip<T>::zip_(const T &head, const Args &... tail) {
  if (head.size() < min_) min_ = head.size();
  
  for (std::size_t i = 0; i < min_; ++i) {
    typename T::const_iterator itr = head.begin();
    std::advance(itr, i);
    items[i].push_back(*itr);
  }

  return zip_(tail...);
}

template<typename T>
void Zip<T>::zip_() {
  items.resize(min_);
}


template<typename T, typename... Args>
typename Zip<T>::container zip(const T &head, const Args &... tail) {
  return Zip<T>(head, tail...);
}
}