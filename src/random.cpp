#include "random.h"

random::random() {
  gen = std::default_random_engine(std::random_device()());
}

size_t random::randomIndex(size_t length) {
  std::uniform_int_distribution<size_t> dist(0, length - 1);
  return dist(gen);
}
