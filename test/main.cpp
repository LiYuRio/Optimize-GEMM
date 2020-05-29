#include <iostream>
#include <fstream>
#include "gemm/utils.h"
#include "gemm/gemm_impls.h"
using namespace std;

int main() {
  int p, m, n, k, lda, ldb, ldc;
  double gflops, duration_time, start_time;
  float *a, *b, *c, *cold, *cref;
  ofstream out;
  out.open("output.dat");
  for (p = PFIRST; p <= PLAST; p += PINC) {
    m = (M == -1 ? p : M);
    n = (N == -1 ? p : N);
    k = (K == -1 ? p : K);

    gflops = 2.0 * m * n * k * 1.0e-09;

    lda = (LDA == -1 ? k : LDA);
    ldb = (LDB == -1 ? n : LDB);
    ldc = (LDC == -1 ? n : LDC);

    a = new float[m * lda];
    b = new float[k * ldb];
    c = new float[m * ldc];
    cold = new float[m * ldc];
    cref = new float[m * ldc];

    random_uniform_matrix(m, k, a, lda, LB, RB);
    random_uniform_matrix(k, n, b, ldb, LB, RB);
    random_uniform_matrix(m, n, cold, ldc, LB, RB);
    start_time = timer();
    reference_sgemm(m, n, k, a, lda, b, ldb, c, ldc);
    duration_time = timer() - start_time;

    cout << "Reference: m = n = k = " << p << ", Gflops = " << gflops / duration_time << "."
         << endl;
    out << m << " " << gflops / duration_time << endl; 

    delete a;
    delete b;
    delete c;
    delete cold;
    delete cref;
  }
  out.close();
}