#ifndef CUHKSZ_ZIP_ZIPFUNCTIONS
#define CUHKSZ_ZIP_ZIPFUNCTIONS
#include <iterator>
#include <vector>
namespace cuhksz {

template<typename T>
class Zip {
 public:
  typedef std::vector<T> container;

  template<typename... Args>
  Zip(const T &head, const Args &... args):
      items(head.size()), min_(head.size()) { // member initialization
    zip_(head, args...);
  }
  inline operator container() const {
    return items;
  };

  inline container operator()() const {
    return items;
  };

 private:

  template<typename... Args>
  void zip_(const T &head, const Args &... tail){
    if (head.size() < min_) min_ = head.size();

    for (std::size_t i = 0; i < min_; ++i) {
      typename T::const_iterator itr = head.begin();
      std::advance(itr, i);
      items[i].push_back(*itr);
    }

    return zip_(tail...);
  };

  void zip_(){
    items.resize(min_);
  }

  container items;

  std::size_t min_;

};

template<typename T, typename... Args>
typename Zip<T>::container zip(const T &head, const Args &... tail) {
  return Zip<T>(head, tail...);
};
}

#endif //CUHKSZ_ZIP_ZIPFUNCTIONS
