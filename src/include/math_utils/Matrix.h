#ifndef CUHKSZ_MATH_MATRIX
#define CUHKSZ_MATH_MATRIX

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

namespace cuhksz {

template <typename ValueType>
class Matrix {
 public:
  explicit Matrix(int n) : Matrix(n, n) {}

  Matrix(int n, int m) : row(n), col(m) {
    elem = new ValueType*[row];
    for (int i = 0; i < row; i++) {
      elem[i] = new ValueType[col];
      std::memset(elem[i], 0, col * sizeof(ValueType));
    }
  }

  Matrix(std::vector<std::vector<int> > ini) {
    row = ini.size();
    col = ini[0].size();
    elem = new ValueType*[row];
    for (int i = 0; i < row; i++) {
      elem[i] = new ValueType[col];
      for (int j = 0; j < col; j++) elem[i][j] = ini[i][j];
    }
  }

  Matrix(const Matrix& src) { deepCopy(src); }

  ~Matrix() { clear(); }

  // allocation
  Matrix& operator=(const Matrix& src) {
    if (this == &src) return *this;
    clear();
    deepCopy(src);
    return *this;
  }

  // index
  ValueType* operator[](int i) const { return elem[i]; }

  friend std::ostream& operator<<(std::ostream& os, const Matrix& src) {
    os << src.toString();
    return os;
  }

  bool operator==(const Matrix& other) const {
    if (row != other.row || col != other.col) return false;
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++)
        if ((*this)[i][j] != other[i][j]) return false;
    return true;
  }

  bool operator!=(const Matrix& other) const {
    return !this->operator==(other);
  }

  Matrix operator*(const Matrix& other) const {
    assert(col == other.row);
    Matrix* ret = new Matrix(row, other.col);
    for (int i = 0; i < ret->row; i++)
      for (int j = 0; j < ret->col; j++)
        for (int k = 0; k < col; k++)
          (*ret)[i][j] += (*this)[i][k] * other[k][j];
    return *ret;
  }

  Matrix& operator*=(const Matrix& other) {
    assert(col == other.row);
    Matrix* ret = new Matrix(row, other.col);
    for (int i = 0; i < ret->row; i++)
      for (int j = 0; j < ret->col; j++)
        for (int k = 0; k < col; k++)
          (*ret)[i][j] += (*this)[i][k] * other[k][j];
    clear();
    *this = *ret;
    return *this;
  }

  Matrix operator+(const Matrix& other) const {
    assert(row == other.row && col == other.col);
    Matrix ret(row, col);
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++) ret[i][j] = (*this)[i][j] + other[i][j];
    return ret;
  }

  Matrix& operator+=(const Matrix& other) {
    assert(row == other.row && col == other.col);
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++) (*this)[i][j] += other[i][j];
    return *this;
  }

  Matrix operator-(const Matrix& other) const {
    assert(row == other.row && col == other.col);
    Matrix ret(row, col);
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++) ret[i][j] = (*this)[i][j] - other[i][j];
    return ret;
  }

  Matrix& operator-=(const Matrix& other) {
    assert(row == other.row && col == other.col);
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++) (*this)[i][j] -= other[i][j];
    return *this;
  }

  void clear() {
    for (int i = 0; i < row; i++) delete[] elem[i];
    delete[] elem;
  }

  void deepCopy(const Matrix& src) {
    row = src.row, col = src.col;
    elem = new ValueType*[row];
    for (int i = 0; i < row; i++) {
      elem[i] = new ValueType[col];
      for (int j = 0; j < col; j++) elem[i][j] = src[i][j];
    }
  }

  friend Matrix& idMat(int n) {
    Matrix* ret = new Matrix(n);
    for (int i = 0; i < n; i++) (*ret)[i][i] = 1;
    return *ret;
  }

  friend Matrix& pow(const Matrix& src, unsigned int n) {
    if (n == 1) {
      Matrix* ret = new Matrix(src);
      return *ret;
    }

    Matrix& ret = pow(src, n >> 1);
    if (n & 1) ret *= src;
    return ret;
  }

  void reduce() {
    Matrix& A = *this;
    for (int i = 0, r = 0; i < row; i++) {
      int nonZeroRow;
      while (r < col) {
        nonZeroRow = -1;
        for (int j = i; j < row; j++)
          if (A[j][r] != 0) {
            nonZeroRow = j;
            break;
          }
        if (nonZeroRow < 0) {
          r++;
        } else {
          std::swap(A.elem[nonZeroRow], A.elem[i]);
          break;
        }
      }
      if (nonZeroRow < 0) return;
      for (int j = col - 1; j > r; j--) A[i][j] /= A[i][r];
      A[i][r] = 1.0;

      for (int j = i + 1; j < row; j++) {
        for (int k = col - 1; k > r; k--) A[j][k] -= A[i][k] * A[j][r];
        A[j][r] = 0.0;
      }
    }
    return;
  }

  std::string toString() const {
    std::string s;
    const Matrix& A = *this;
    for (int i = 0; i < row; i++) {
      s += std::to_string(A[i][0]);
      for (int j = 1; j < col; j++) s += ", " + std::to_string(A[i][j]);
      s += "\n";
    }
    return s;
  }

 private:
  ValueType** elem;
  int row;
  int col;
};

}  // namespace cuhksz

#endif  // CUHKSZ_MATH_MATRIX
