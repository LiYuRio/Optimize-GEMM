#include "gemm/gemm_impls.h"

#define A(i, j) a[(i)*lda + (j)]
#define B(i, j) b[(i)*ldb + (j)]
#define C(i, j) c[(i)*ldc + (j)]

void reference_sgemm(int m, int n, int k, float *a, int lda, float *b, int ldb,
                     float *c, int ldc) {
  int i, j, p;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      for (p = 0; p < k; p++) {
        C(i, j) = C(i, j) + A(i, p) * B(p, j);
      }
    }
  }
}
