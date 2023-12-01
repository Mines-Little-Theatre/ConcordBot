#ifndef RNG_H
#define RNG_H

#include <random>

class rng {
private:
  std::default_random_engine gen;

public:
  rng();
  size_t randomIndex(size_t length);
};

#endif // RNG_H
