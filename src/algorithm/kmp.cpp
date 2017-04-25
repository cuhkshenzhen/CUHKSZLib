#include "algorithm.h"

#include <memory>
#include <string>

namespace cuhksz {
int kmpSearch(const std::string& base, const std::string& pattern,
              std::size_t start) {
  // generate next table
  unsigned long psize = pattern.size();
  std::unique_ptr<int[]> next = std::unique_ptr<int[]>(new int[psize]);
  next[0] = -1;
  int j = 0;
  int k = -1;
  while (j < psize - 1) {
    if (k == -1 || pattern[j] == pattern[k]) {
      j++;
      k++;
      if (pattern[j] == pattern[k]) {
        next[j] = next[k];
      } else {
        next[j] = k;
      }
    } else {
      k = next[k];
    }
  }

  size_t m = start;
  int i = 0;
  unsigned long bsize = base.size();
  while (m < bsize && i < psize) {
    if (i == -1 || base[m] == pattern[i]) {
      m++;
      i++;
    } else {
      i = next[i];
    }
  }
  if (i == psize) return (int) (m - i);
  return -1;
}
}  // namespace cuhksz
