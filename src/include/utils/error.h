#ifndef CUHKSZ_UTILS_ERROR
#define CUHKSZ_UTILS_ERROR

#include <cstdio>

#ifdef _MSC_VER
// or __FUNCSIG__
#define error(msg)                                                       \
  std::fprintf(stderr, "Error occurs in `%s`, %s\n", __FUNCTION__, msg); \
  exit(EXIT_FAILURE);
#else
#define error(msg)                                                        \
  std::fprintf(stderr, "Error occurs in `%s`, %s\n", __PRETTY_FUNCTION__, \
               msg);                                                      \
  exit(EXIT_FAILURE);
#endif

#endif  // CUHKSZ_UTILS_ERROR
