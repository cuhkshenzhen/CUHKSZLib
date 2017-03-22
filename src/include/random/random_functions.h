#ifndef CUHKSZ_RANDOM_RANDOMFUNCTIONS
#define CUHKSZ_RANDOM_RANDOMFUNCTIONS

#include "./Random.h"
namespace cuhksz {
int randomInt();
int randomInt(int min);
int randomInt(int min, int max);
double randomDouble(double min, double max);
double randomDouble(double max);
double randomDouble();
bool randomBool();
}  // namespace cuhksz
#endif  // CUHKSZ_RANDOM_RANDOMFUNCTIONS
