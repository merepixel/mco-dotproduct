#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern double dotProductx64(size_t n, double* result, double* arr1, double* arr2);

void dotProduct(size_t n, double* result, double* arr1, double* arr2) {
    int i;
    float ans = 0.0;

    for (i = 0; i < n; i++) {
        ans = ans + (arr1[i] * arr2[i]);
    }

    *result = ans;
}


int main() {
    const size_t N = 1 << 20;
    const size_t ARRAY_BYTES = N * sizeof(double);

    clock_t begin, end;

    double time_taken;
    double average_time;

    double* array1;
    double* array2;
    double* answer1;
    double* answer2;
    array1 = (double*)malloc(N * sizeof(double));
    array2 = (double*)malloc(N * sizeof(double));
    answer1 = (double*)malloc(N * sizeof(double));
    answer2 = (double*)malloc(N * sizeof(double));
    int i;
    for (i = 0; i < N; i++) {
        array1[i] = 1;
        array2[i] = 2;
    }

    dotProduct(N, answer1, array1, array2);

    int loop = 30;
    int j;

    begin = clock();

    for (j = 0; j < loop; j++) {
        dotProduct(N, answer1, array1, array2);
    }
    end = clock();

    time_taken = ((double)(end - begin)) * 1e3 / CLOCKS_PER_SEC;
    average_time = time_taken / loop;

    printf("C functions take %lf milliseconds for array size %zu \n", average_time, N);


    // -------------x86-64-------------
    dotProductx64(N, answer2, array1, array2);

    int loop2 = 30;
    int k;

    begin = clock();
    for (int k = 0; k < loop2; k++) {
        dotProductx64(N, answer2, array1, array2);
    }
    end = clock();

    time_taken = ((double)(end - begin)) * 1e3 / CLOCKS_PER_SEC;
    average_time = time_taken / loop2;

    printf("Assembly functions takes %lf milliseconds for array size %zu \n", average_time, N);


    return 0;

}