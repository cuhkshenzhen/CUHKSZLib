#ifndef CUHKSZ_STRINGUTILS_STRINGCAST
#define CUHKSZ_STRINGUTILS_STRINGCAST
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
namespace cuhksz {
/**
 * Convert your string to a new type.
 *
 * Usage:
 * ```
 * (int)cuhksz::stringCast<int>("12345") // or
 * cuhksz::stringCast<int>("12345")()
 * ```
 * @tparam T Type to convert
 */
template <typename T>
class stringCast {
 public:
  stringCast(const std::string &from) : m_from(from) {}
  operator T() const {
    std::stringstream strStream(m_from);
    T casted;
    try {
      strStream >> casted;
    } catch (std::exception &e) {
      std::cerr << "not able to cast: " << e.what() << std::endl;
      return T(0);
    }
    return casted;
  }
  T operator()() const { return (T) * this; }

 private:
  const std::string &m_from;
};
}  // namespace cuhksz
#endif  // CUHKSZ_STRINGUTILS_STRINGCAST
