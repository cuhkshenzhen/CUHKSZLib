#include <iostream>
#include <string>
#include "utils.h"
namespace cuhksz{
  void error(std::string errorMsg) {
    std::cerr << "Unexpected Error in CUHKSZLib:" << std::endl;
    std::cerr << errorMsg << std::endl;
    exit(1);
  }
}