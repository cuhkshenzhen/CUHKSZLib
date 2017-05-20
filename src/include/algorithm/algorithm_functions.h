#ifndef CUHKSZ_ALGORITHM_ALGORITHMFUNCTIONS
#define CUHKSZ_ALGORITHM_ALGORITHMFUNCTIONS

#include <string>

namespace cuhksz {
/**
  String searching by [Knuth–Morris–Pratt
  algorithm](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm).
  This is a fast string searching algorithm to find the occurrence of a
  substring.
  @param base The string to search to search from
  @param pattern The substring to be searched
  @param start The position to start searching.
  @return The index of the first occurrence of `pattern` in `base`, searching
    from `start`. If no occurrence, return -1.
**/
int kmpSearch(const std::string& base, const std::string& pattern,
              std::size_t start = 0);

/**
  Compute the edit distance of two strings.
  The edit distance, or [Levenshtein
  distance](https://en.wikipedia.org/wiki/Levenshtein_distance), is the least
  number of operations(adding, deleting, or replacing) to change from one string
  to another. For example, the edit distance between `this` and `thus` is `1`.
**/
int editDistance(const std::string& str1, const std::string& str2);

}  // namespace cuhksz

#endif  // CUHKSZ_ALGORITHM_ALGORITHMFUNCTIONS
