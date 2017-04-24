#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include "string_utils/Trie.h"

int main() {
  std::ifstream fin("EnglishWords.txt");
  std::string tmp;

  std::set<std::string> set;
  cuhksz::Trie trie;
  int i = 0;
  while (fin) {
    std::getline(fin, tmp);
    trie.insert(tmp);
    set.insert(tmp);
    i++;
    if (i % 10000 == 0) printf("Processed:%d\n", i);
  }
  for (auto& s : set) {
    if (!trie.contain(s)) std::cout << s << std::endl;
  }
}
