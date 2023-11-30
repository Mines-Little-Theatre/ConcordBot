#ifndef RANDOM_H
#define RANDOM_H

#include <random>

class random {
private:
  std::default_random_engine gen;

public:
  random();
  size_t randomIndex(size_t max);
};

#endif // RANDOM_H
