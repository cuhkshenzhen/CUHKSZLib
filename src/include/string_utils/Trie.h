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
  [Trie](https://en.wikipedia.org/wiki/Trie), a `Set` like data structure
  optimized for storing strings.
  The implementation is a DAT(double array trie),
  by J. Aoe, K. Morimoto and K. Sato. *An efficient implementation of trie
   structures*. 1992.

  So this implementation takes little space to store data, and is efficient
  in retrieving and deleting elements, but works bad in inserting. By default,
  this Trie only accept strings with only lower case letters, and you can change
  this behavior by passing two function pointers to the constructer (see below).

  Usage:
  ```
  Trie trie;
  // add an element
  trie.insert("black");
  // add more elements
  trie.insert("white");
  trie.insert("red");
  // check belongingness
  if (trie.contain("red")) { do something ... }
  // delete element
  trie.remove("white");
  // loop through all elements
  for (auto s : trie) { do something with s ... }
  ```
**/
class Trie {
 public:
  /**
    Construct a `Trie` object with default settings (only receives lower
    letters).

    __Note:__ because of the efficiency, `Trie` will not check all the input
    strings. Thus the inputs with non-lower letters do not always fail.
  **/
  Trie() : Trie(private_::mapChar, private_::mapInt) {}

  /**
    Construct a `Trie` object with custom "adapters", i.e. ways to map the
    characters in the string with integers. Requirements for the `mapChar` and
    `mapInt` are:
    1. ``mapChar('\001')`` should return 1 and `mapInt(1)` should return
      ``'\001'``.
    2. `mapInt(mapChar(ch)) == ch` and `mapChar(mapInt(num)) == num`
    3. The mapped integers should start with 1 (as for ``'\001'``) and increase
      sequentially

    The default implementation of this two functions are:
    ```
    int mapChar(char ch) {
      if (ch == '\001') return 1;
      if (ch < 'a' || ch > 'z') error("Trie only accept lower letter a-z.");
      return ch - 'a' + 2;
    }

    char mapInt(int n) {
      if (n == 1) return '\001';
      return n - 2 + 'a';
    }
    ```
  **/
  Trie(int (*mapChar)(char), char (*mapInt)(int));

  /**
    Return the number of elements in the trie.
  **/
  int size() { return size_; }

  /**
    Insert the element `str` to the trie.
  **/
  void insert(const std::string& str);

  /**
    Check if the element `str` is in the trie.
  **/
  bool contain(const std::string& str);

  /**
    Remove the element `str` from the trie.
  **/
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
  int size_;

  bool retrieve(const std::string&);
  void insert_(const std::string&);
  bool remove_(const std::string&);
  bool visit(int* n, int* offset, std::vector<int>*);

  int checkAvailable(const std::vector<int>&);
  int checkAvailable(int);
  int checkAvailable(int, int);

  std::vector<int> outArcs(int);
  void setTail(int, int, const std::string&);
  int nextTail();
  /// \cond NODOC
  class StringAdapter {
   public:
    explicit StringAdapter(const std::string& str) : underlying(str) {}
    static int (*mapChar)(char);

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
  /// \endcond
 public:
  /**
    Iterator of the `Trie`, it is an Input Iterator with `std::string` as type.
  **/
  class iterator : public std::iterator<std::input_iterator_tag, std::string> {
    /// \cond NODOC
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
          std::string ending = trie_->tail.get(-i - 2);
          rtn += ending.substr(0, ending.size() - 1);
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
      bool result = trie_->visit(&n_, &offset_, &buffer_);
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
    /// \endcond
  };
  /**
    Return the `iterator` of trie object pointing to the first element.
  **/
  iterator begin() { return iterator(this); }

  /**
    Return the `iterator` of trie object pointing to the end.
  **/
  iterator end() { return iterator(this, true); }
};
}  // namespace cuhksz

#endif  // CUHKSZ_STRINGUTILS_TRIE
