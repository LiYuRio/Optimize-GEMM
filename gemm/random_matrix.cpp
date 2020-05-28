#include <memory>
#include <random>

#include "gemm/utils.h"

#define A(i, j) a[(j)*lda + (i)]

void random_uniform_matrix(int m, int n, float *a, int lda, int l, int r) {
  int random_seed = std::random_device{}();
  std::unique_ptr<std::mt19937> random_generator;
  random_generator.reset(new std::mt19937(random_seed));
  std::uniform_real_distribution<float> distribution(l, r);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      A(i, j) = distribution(*random_generator.get());
    }
  }
}
