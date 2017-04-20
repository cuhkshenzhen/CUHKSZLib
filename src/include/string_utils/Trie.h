#ifndef CUHKSZ_STRINGUTILS_TRIE
#define CUHKSZ_STRINGUTILS_TRIE

#include <iterator>
#include <queue>
#include <string>
#include <vector>

namespace cuhksz {

namespace private_ {
int mapChar(char ch);
char mapInt(int n);

template <typename Type = int, int initialLength = 26>
class AutoArray {
 public:
  explicit AutoArray(Type default_ = -1) : defaultValue(default_) {
    vec.resize(initialLength, defaultValue);
    size_ = initialLength;
  }
  Type get(int pos) { return vec[pos]; }

  Type getWithCheck(int pos) {
    if (pos < size_) return vec[pos];
    return defaultValue;
  }

  void set(int pos, Type value) {
    if (pos >= size_) {
      vec.resize(pos + 1 + initialLength, defaultValue);
      size_ = pos + 1 + initialLength;
    }
    vec[pos] = value;
  }

  int size() { return size_; }

 private:
  std::vector<Type> vec;
  Type defaultValue;
  int size_;
};

}  // namespace private_

/**
  The implementation is a DAT(double array trie),
  by J. Aoe, K. Morimoto and K. Sato. *An efficient implementation of trie
   structures*. 1992.
**/
class Trie {
 public:
  Trie() : Trie(private_::mapChar, private_::mapInt) {}
  Trie(int (*mapChar)(char), char (*mapInt)(int));
  void insert(const std::string& str);
  bool contain(const std::string& str);
  void remove(const std::string& str);

 private:
  private_::AutoArray<> base;
  private_::AutoArray<> check;
  private_::AutoArray<std::string, 0> tail{""};
  int pos;
  static constexpr char endChar = '\001';
  int (*mapChar)(char);
  char (*mapInt)(int);
  std::queue<int> tailList;

  bool retrieve(const std::string&);
  void insert_(const std::string&);
  void remove_(const std::string&);
  bool travel(int* n, int* offset, std::vector<int>*);

  int checkAvailable(const std::vector<int>&);
  int checkAvailable(int);
  int checkAvailable(int, int);

  std::vector<int> outArcs(int);
  void setTail(int, int, const std::string&);
  int nextTail();

  class StringAdapter {
   public:
    explicit StringAdapter(const std::string& str) : underlying(str) {}
    static int (*mapChar)(char);
    // static std::function<int(char)> mapChar;

   private:
    const std::string& underlying;

   public:
    class iterator : public std::iterator<std::input_iterator_tag, const int> {
     public:
      explicit iterator(const std::string* str) : iterator(str, 0) {}
      iterator(const std::string* str, std::size_t index)
          : index_(index), str_(str) {}
      iterator(const iterator& iter) : index_(iter.index_), str_(iter.str_) {}

      int operator*() {
        auto ch = (*str_)[index_];
        return mapChar(ch);
      }

      iterator& operator++() {
        index_++;
        return *this;
      }

      bool operator==(const iterator& iter) {
        return str_ == iter.str_ && index_ == iter.index_;
      }

      bool operator!=(const iterator& iter) { return !(*this == iter); }

     private:
      std::size_t index_;
      const std::string* str_;
    };
    iterator begin() { return iterator(&underlying); }
    iterator end() { return iterator(&underlying, underlying.size()); }
  };

 public:
  class iterator : public std::iterator<std::input_iterator_tag, std::string> {
   public:
    explicit iterator(Trie* trie) : iterator(trie, false) {}
    iterator(Trie* trie, bool end) : trie_(trie), n_(0), offset_(1), end_(end) {
      ++(*this);
    }
    iterator(const iterator& iter)
        : trie_(iter.trie_),
          n_(iter.n_),
          offset_(iter.offset_),
          buffer_(iter.buffer_),
          end_(iter.end_) {}

    std::string operator*() {
      std::string rtn;
      for (auto i : buffer_) {
        if (i == 1) break;
        if (i < 0) {
          std::string tail = trie_->tail.get(-i - 2);
          if (tail != std::string(1, endChar)) rtn += tail;
          break;
        }
        rtn += trie_->mapInt(i);
      }
      return rtn;
    }

    iterator& operator++() {
      if (end_) return *this;
      if (!buffer_.empty()) {
        buffer_.pop_back();
        buffer_.pop_back();
      }
      bool result = trie_->travel(&n_, &offset_, &buffer_);
      if (!result) end_ = true;
      return *this;
    }

    bool operator==(const iterator& iter) {
      if (end_ || iter.end_) {
        if (end_ && iter.end_) {
          return true;
        } else {
          return false;
        }
      }
      return trie_ == iter.trie_ && n_ == iter.n_ && offset_ == iter.offset_ &&
             buffer_ == iter.buffer_;
    }

    bool operator!=(const iterator& iter) { return !(*this == iter); }

   private:
    Trie* trie_;

    int n_;
    int offset_;
    std::vector<int> buffer_;
    bool end_;
  };
  iterator begin() { return iterator(this); }
  iterator end() { return iterator(this, true); }
};
}  // namespace cuhksz

#endif  // CUHKSZ_STRINGUTILS_TRIE
