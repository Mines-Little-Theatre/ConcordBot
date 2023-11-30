#include "rng.h"

rng::rng() { gen = std::default_random_engine(std::random_device()()); }

size_t rng::randomIndex(size_t length) {
  std::uniform_int_distribution<size_t> dist(0, length - 1);
  return dist(gen);
}
