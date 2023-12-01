#ifndef RNG_H
#define RNG_H

#include <random>

class RandomNumberGenerator {
private:
  std::default_random_engine gen;

public:
  RandomNumberGenerator();
  int randomIndex(int length);
};

#endif // RNG_H
