#ifndef BLAS_H
#define BLAS_H

//функция AXPY (y = a * x + y) для векторов длины n
void c_axpy(int n, double a, const double *x, double *y);

#endif