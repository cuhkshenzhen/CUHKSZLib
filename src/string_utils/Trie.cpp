#include "string_utils/Trie.h"

#include <string>
#include <vector>

namespace cuhksz {

namespace private_ {
int mapChar(char ch) {
  if (ch == '\001') return 1;
  return ch - 'a' + 2;
}

char mapInt(int n) {
  if (n == 1) return '\001';
  return n - 2 + 'a';
}
}  // namespace private_

namespace {
std::string commonPrefix(const std::string& string1,
                         const std::string& string2) {
  std::string rtn;
  std::string const* str1;
  std::string const* str2;
  if (string1.size() > string2.size()) {
    str1 = &string2;
    str2 = &string1;
  } else {
    str1 = &string1;
    str2 = &string2;
  }
  unsigned long size = str1->size();
  bool flag = false;
  for (unsigned long i = 0; i < size; i++) {
    if ((*str1)[i] != (*str2)[i]) {
      rtn = str1->substr(0, i);
      flag = true;
      break;
    }
  }
  if (!flag) {
    if (str1->size() == str2->size()) return "";
    rtn = *str1;
  }
  return rtn;
}
}  // namespace

// Used to fix undefined symbols error
int (*Trie::StringAdapter::mapChar)(char) = nullptr;

Trie::Trie(int (*mapChar)(char), char (*mapInt)(int)) {
  base.set(0, 0);
  pos = 0;
  this->mapChar = mapChar;
  this->mapInt = mapInt;
  StringAdapter::mapChar = mapChar;
  size_ = 0;
}

bool Trie::retrieve(const std::string& word) {
  int n = 0;
  StringAdapter adapter(word);
  int ind = 0;
  for (int i : adapter) {
    ind++;
    int next = base.get(n) + i;
    if (check.get(next) != n) return false;
    n = next;
    if (base.get(n) < -1) break;
  }
  if (ind == (int)word.size()) return true;
  return tail.getWithCheck(-base.get(n) - 2) == word.substr(ind);
}

bool Trie::visit(int* n, int* offset, std::vector<int>* buffer) {
  for (; *offset < 28; (*offset)++) {
    int next = base.getWithCheck(*n) + *offset;
    if (check.getWithCheck(next) != *n) continue;
    buffer->push_back(*offset);
    if (*offset == 1) {
      buffer->push_back(-1);
      (*offset)++;
      return true;
    }
    if (base.getWithCheck(next) < -1) {
      buffer->push_back(base.getWithCheck(next));
      (*offset)++;
      return true;
    }
    *offset = 1;
    *n = next;
    return visit(n, offset, buffer);
  }
  if (buffer->size() == 1 || buffer->empty()) {
    return false;
  } else {
    buffer->pop_back();
    *offset = buffer->back() + 1;
    *n = check.getWithCheck(*n);
    return visit(n, offset, buffer);
  }
}

void Trie::insert_(const std::string& word) {
  int n = 0;
  StringAdapter adapter(word);
  int ind = 0;
  for (int i : adapter) {
    ind++;
    int next = base.get(n) + i;
    if (check.getWithCheck(next) == -1) {
      setTail(n, next, word.substr(ind));
      break;
    } else if (check.get(next) == n && base.get(next) < -1) {
      int temp = -base.get(next) - 2;
      const std::string& tail_temp = tail.get(temp);
      auto prefix = commonPrefix(word.substr(ind), tail_temp);
      int prefix_length = prefix.size();

      for (int j : StringAdapter(prefix)) {
        int available = checkAvailable(j);
        base.set(next, available);
        check.set(available + j, next);
        next = base.get(next) + j;
      }

      int char_val_tail = mapChar(tail_temp[prefix_length]);
      int char_val_new = mapChar(word[ind + prefix_length]);

      int q = checkAvailable(char_val_tail, char_val_new);
      base.set(next, q);
      if (tail_temp[prefix_length] == endChar) {
        base.set(q + char_val_tail, -1);
        tailList.push(temp);
      } else {
        base.set(q + char_val_tail, -temp - 2);
        tail.set(temp, tail_temp.substr(prefix_length + 1));
      }
      check.set(q + char_val_tail, next);

      if (word[ind + prefix_length] == endChar) {
        base.set(q + char_val_new, -1);
      } else {
        int p = nextTail();
        base.set(q + char_val_new, -p - 2);
        tail.set(p, word.substr(ind + prefix_length + 1));
      }
      check.set(q + char_val_new, next);
      break;
    } else if (check.get(next) != n) {
      std::vector<int> list_n = outArcs(n);
      std::vector<int> list_check = outArcs(check.get(next));
      int node_modify;
      int new_base;
      int node_other = n;
      std::vector<int>* modify_list;

      if (list_n.size() + 1 < list_check.size()) {
        node_modify = n;
        modify_list = &list_n;
        modify_list->push_back(i);
        new_base = checkAvailable(*modify_list);
        modify_list->pop_back();
      } else {
        node_modify = check.get(next);
        modify_list = &list_check;
        new_base = checkAvailable(*modify_list);
      }

      int temp_base = base.get(node_modify);
      base.set(node_modify, new_base);
      for (int j : *modify_list) {
        int node_old = temp_base + j;
        int node_new = new_base + j;

        if (node_old == node_other) node_other = node_new;

        base.set(node_new, base.get(node_old));
        check.set(node_new, check.get(node_old));
        if (base.get(node_old) > -1) {
          std::vector<int> list = outArcs(node_old);
          for (int k : list) {
            check.set(base.get(node_old) + k, node_new);
          }
        }
        base.set(node_old, -1);
        check.set(node_old, -1);
      }

      int temp_node = base.get(node_other) + i;
      if (i == 1) {
        base.set(temp_node, -1);
      } else {
        int p = nextTail();
        base.set(temp_node, -p - 2);
        tail.set(p, word.substr(ind));
      }
      check.set(temp_node, node_other);
      break;
    }
    n = next;
  }
}

bool Trie::remove_(const std::string& word) {
  int n = 0;
  StringAdapter adapter(word);
  int ind = 0;
  for (int i : adapter) {
    ind++;
    int next = base.get(n) + i;
    if (check.get(next) != n) return false;
    n = next;
    if (base.get(n) < -1) {
      if (tail.getWithCheck(-base.get(n) - 2) == word.substr(ind)) {
        base.set(n, -1);
        check.set(n, -1);
        return true;
      }
      return false;
    }
  }
  check.set(n, -1);
  return true;
}

inline int Trie::checkAvailable(const std::vector<int>& list) {
  int size = list.size();
  for (int q = 0;; q++) {
    bool flag = true;
    for (int i = 0; i < size; i++) {
      if (check.getWithCheck(q + list[i]) != -1) {
        flag = false;
        break;
      }
    }
    if (flag) return q;
  }
}

inline int Trie::checkAvailable(int i, int j) {
  for (int q = 0;; q++) {
    if (check.getWithCheck(q + i) == -1 && check.getWithCheck(q + j) == -1)
      return q;
  }
}

inline int Trie::checkAvailable(int i) {
  for (int q = 0;; q++) {
    if (check.getWithCheck(q + i) == -1) return q;
  }
}

inline std::vector<int> Trie::outArcs(int n) {
  std::vector<int> rtn;
  int base_n = base.get(n);
  for (int i = 1; i < 28; i++) {
    if (check.getWithCheck(base_n + i) == n) rtn.push_back(i);
  }
  return rtn;
}

void Trie::setTail(int n, int next, const std::string& rest) {
  int p = nextTail();
  tail.set(p, rest);
  base.set(next, -p - 2);
  check.set(next, n);
}

int Trie::nextTail() {
  if (tailList.empty()) return pos++;

  int rtn = tailList.front();
  tailList.pop();
  return rtn;
}

void Trie::insert(const std::string& str) {
  if (contain(str)) return;
  insert_(str + endChar);
  size_++;
}
bool Trie::contain(const std::string& str) { return retrieve(str + endChar); }
void Trie::remove(const std::string& str) {
  if (remove_(str + endChar)) size_--;
}

}  // namespace cuhksz
