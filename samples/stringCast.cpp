#include "string_utils.h"
#include <iostream>
using namespace cuhksz;

int main() {
  std::cout << "Casting string 12345 to ";
  std::cout << typeid(stringCast<int>("12345")).name() << std::endl;
  std::cout << "Result: " << stringCast<int>("12345");
}
