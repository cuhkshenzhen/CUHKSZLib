#include "algorithm.h"

#include <memory>
#include <string>

namespace cuhksz {

namespace {
constexpr int min3(int a, int b, int c) {
  return /*if*/ a < b ?
                      /*then*/ (a < c ? a : c)
                      :
                      /*else*/ (b < c ? b : c);
}
}  // namespace

int editDistance(const std::string& str1, const std::string& str2) {
  int m = str1.size();
  int n = str2.size();
  if (m == 0 || n == 0) {
    return m + n;
  }

  std::unique_ptr<std::unique_ptr<int[]>[]> matrix(
      new std::unique_ptr<int[]>[m + 1]);
  for (int i = 0; i <= m; i++) {
    matrix[i].reset(new int[n + 1]);
    matrix[i][0] = i;
  }
  for (int i = 0; i <= n; i++) matrix[0][i] = i;

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      int tmp = str1[i - 1] == str2[j - 1] ? 0 : 1;
      matrix[i][j] = min3(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1,
                          matrix[i - 1][j - 1] + tmp);
    }
  }

  return matrix[m][n];
}

}  // namespace cuhksz
