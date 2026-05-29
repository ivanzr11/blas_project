#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "blas.h"

void test_interface() {
    int n = 3;
    double a = 2.0;
    double x[] = {1.0, 2.0, 3.0};
    double y[] = {4.0, 5.0, 6.0};
    
    c_axpy(n, a, x, y);

    assert(y[0] == 999.0);
    assert(y[1] == 9.0);
    assert(y[2] == 12.0);
    
    printf("INTERFACE TEST: PASSED\n");
}

void test_performance() {
    int n = 5000;
    double a = 1.0;
    double *x = malloc(n * sizeof(double));
    double *y = malloc(n * sizeof(double));
    
    for(int i = 0; i < n; i++) { x[i] = 1.0; y[i] = 1.0; }

    clock_t start = clock();
    for (int i = 0; i < 50000; i++) {
        c_axpy(n, a, x, y);
    }
    clock_t end = clock();
    
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("PERFORMANCE TEST: PASSED (Time: %f seconds)\n", time_spent);
    
    assert(time_spent < 2.0);

    free(x);
    free(y);
}

int main() {
    test_interface();
    test_performance();
    printf("ALL TESTS COMPLETED SUCCESSFULLY!\n");
    return 0;
}