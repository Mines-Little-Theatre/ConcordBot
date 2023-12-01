#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator()
    : gen(std::default_random_engine(std::random_device()())) {}

int RandomNumberGenerator::randomIndex(int length) {
  std::uniform_int_distribution<int> dist(0, length - 1);
  return dist(gen);
}
