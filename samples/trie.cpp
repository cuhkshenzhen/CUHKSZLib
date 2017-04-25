#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include "string_utils/Trie.h"

int main() {
  // Words are from https://github.com/dwyl/english-words
  // preprocessed to remove words that have digits
  std::ifstream fin("EnglishWords.txt");
  if (!fin) {
    printf("Cannot open `EnglishWords.txt`!\n");
    exit(1);
  }
  std::string tmp;

  std::set<std::string> set;
  cuhksz::Trie trie;
  int i = 0;
  while (fin) {
    std::getline(fin, tmp);
    trie.insert(tmp);
    set.insert(tmp);
    i++;
    if (i % 10000 == 0) printf("Processed: %d words\n", i);
  }
  for (auto& s : set) {
    if (!trie.contain(s)) std::cout << s << std::endl;
  }
  printf("Above are the words that the Trie has problem with, if no, good!\n");
}
