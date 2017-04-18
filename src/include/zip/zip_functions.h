//
// Created by Xiaoxing Ye on 18/04/2017.
//

#ifndef CUHKSZ_ZIP_ZIPFUNCTIONS
#define CUHKSZ_ZIP_ZIPFUNCTIONS
namespace cuhksz {

template<typename T>
class Zip {
 public:
  typedef std::vector<T> container;

  template<typename... Args>
  Zip(const T &head, const Args &... args);

  inline operator container() const {
    return items;
  };

  inline container operator()() const {
    return items;
  };

 private:

  template<typename... Args>
  void zip_(const T &head, const Args &... tail);

  inline void zip_();

  container items;

  std::size_t min_;

};

template<typename T, typename... Args>
typename Zip<T>::container zip(const T &head, const Args &... tail);
}

#endif //CUHKSZ_ZIP_ZIPFUNCTIONS
