#include "blas.h"

void c_axpy(int n, double a, const double *x, double *y) {
    for (int i = 0; i < n; i++) {
        y[i] = a * x[i] + y[i];
    }
}