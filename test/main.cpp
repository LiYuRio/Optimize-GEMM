#include <iostream>
#include "gemm/utils.h"
using namespace std;

int main() {
  int p, m, n, k, lda, ldb, ldc;
  double gflops;
  float *a, *b, *c, *cold, *cref;
  for (p = PFIRST; p <= PLAST; p += PINC) {
    m = (M == -1 ? p : M);
    n = (N == -1 ? p : N);
    k = (K == -1 ? p : K);

    gflops = 2.0 * m * n * k * 1.0e-09;

    lda = (LDA == -1 ? m : LDA);
    ldb = (LDB == -1 ? k : LDB);
    ldc = (LDC == -1 ? m : LDC);

    a = new float[lda * k];
    b = new float[ldb * n];
    c = new float[ldc * n];
    cold = new float[ldc * n];
    cref = new float[ldc * n];

    random_uniform_matrix(m, k, a, lda, LB, RB);
    random_uniform_matrix(k, n, b, ldb, LB, RB);
    random_uniform_matrix(m, n, cold, ldc, LB, RB);

    delete a;
    delete b;
    delete c;
    delete cold;
    delete cref;
  }
}