#ifndef CUHKSZ_ALGORITHM_ALGORITHMFUNCTIONS
#define CUHKSZ_ALGORITHM_ALGORITHMFUNCTIONS

#include <string>

namespace cuhksz {
/**
  https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
*/
int kmpSearch(const std::string& base, const std::string& pattern,
              std::size_t start = 0);

/**
  https://en.wikipedia.org/wiki/Levenshtein_distance
*/
int editDistance(const std::string& str1, const std::string& str2);

}  // namespace cuhksz

#endif  // CUHKSZ_ALGORITHM_ALGORITHMFUNCTIONS
