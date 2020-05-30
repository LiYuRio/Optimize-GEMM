#include "gemm/gemm_impls.h"

#define A(i, j) a[(i)*lda + (j)]
#define B(i, j) b[(i)*ldb + (j)]
#define C(i, j) c[(i)*ldc + (j)]

void add_dot_1x4(int k, float *a, int lda, float *b, int ldb, float *c,
                 int ldc) {
  int p;
  for (p = 0; p < k; p++) {
    C(0, 0) += A(0, p) * B(p, 0);
    C(0, 1) += A(0, p) * B(p, 1);
    C(0, 2) += A(0, p) * B(p, 2);
    C(0, 3) += A(0, p) * B(p, 3);
  }
}

void optimize_sgemm_v0(int m, int n, int k, float *a, int lda, float *b,
                       int ldb, float *c, int ldc) {
  int i, j, p;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j+=4) {
      add_dot_1x4(k, &A(i, 0), lda, &B(0, j), ldb, &C(i, j), ldc);
    }
  }
}
