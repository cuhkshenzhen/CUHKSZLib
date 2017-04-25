#include "string_utils.h"
#include <iostream>

int main() {
  std::cout << "Casting string 12345 to ";
  std::cout << typeid(cuhksz::stringCast<int>("12345")).name() << std::endl;
  std::cout << "Result: " << (int)cuhksz::stringCast<int>("12345");
}
