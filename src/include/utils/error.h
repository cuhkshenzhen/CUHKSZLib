#ifndef CUHKSZ_UTILS_ERROR
#define CUHKSZ_UTILS_ERROR

#include <cstdio>
#include <iostream>

#ifdef _MSC_VER
// or __FUNCSIG__
#define error(msg)                                                   \
  {                                                                  \
    std::cerr << "Error occurs in `" << __FUNCTION__ << "`, " << msg \
              << std::endl;                                          \
    exit(EXIT_FAILURE);                                              \
  }                                                                  \
  (void)(0)  // force a `;` after error()
#else
#define error(msg)                                                          \
  {                                                                         \
    std::cerr << "Error occurs in `" << __PRETTY_FUNCTION__ << "`, " << msg \
              << std::endl;                                                 \
    exit(EXIT_FAILURE);                                                     \
  }                                                                         \
  (void)(0)
#endif

#endif  // CUHKSZ_UTILS_ERROR
