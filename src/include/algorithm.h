#ifndef CUHKSZ_ALGORITHM
#define CUHKSZ_ALGORITHM

#include <string>

namespace cuhksz {
/**
  https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
*/
int kmpSearch(std::string base, std::string pattern, std::size_t start = 0);
}  // namespace cuhksz
#endif  // CUHKSZ_ALGORITHM
