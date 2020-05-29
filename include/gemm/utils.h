#pragma once

#define PFIRST 40
#define PLAST  800
#define PINC   40

#define M -1
#define N -1
#define K -1

#define LDA -1
#define LDB -1
#define LDC -1

#define LB 1
#define RB 10

void random_uniform_matrix(int m, int n, float *a, int lda, int l, int r);
double timer();