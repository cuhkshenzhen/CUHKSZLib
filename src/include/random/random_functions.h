#ifndef CUHKSZ_RANDOM_RANDOMFUNCTIONS
#define CUHKSZ_RANDOM_RANDOMFUNCTIONS

#include "random/Random.h"
namespace cuhksz {

/**
  Produce a random `int` out of all possible `int` values.

  @sa Random::nextInt()
**/
int randomInt();

/**
  Produce a random `int` in the range [0, `max`), i.e. includes 0 but
  excludes `max`.

  @sa Random::nextInt(int max)
**/
int randomInt(int max);

/**
  Produce a random `int` in the range [`min`, `max`), i.e. includes the `min`
  but excludes the `max`.

  @sa Random::nextInt(int min, int max)
**/
int randomInt(int min, int max);

/**
  Produce a random `double` in the range [`min`, `max`).

  @sa Random::nextDouble(double min, double max)
**/
double randomDouble(double min, double max);

/**
  Produce a random `double` in the range [0, `max`).

  @sa Random::nextDouble(double max)
**/
double randomDouble(double max);

/**
  Produce a random `double` in the range [0, 1).

  @sa Random::nextDouble();
**/
double randomDouble();

/**
  Produce a random `bool` with the probability of 0.5 `true` and 0.5 `false`.

  @sa Random::nextBool()
**/
bool randomBool();
}  // namespace cuhksz
#endif  // CUHKSZ_RANDOM_RANDOMFUNCTIONS
