#pragma once

void reference_sgemm(int m, int n, int k, float *a, int lda, float *b, int ldb,
                     float *c, int ldc);
void optimize_sgemm_v0(int m, int n, int k, float *a, int lda, float *b,
                       int ldb, float *c, int ldc);