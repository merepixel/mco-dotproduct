#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern double dotProductx64(size_t n, double* result, double* arr1, double* arr2);

void dotProduct(size_t n, double* result, double* arr1, double* arr2) {
    int i;
    double ans = 0.0;

    for (i = 0; i < n; i++) {
        ans = ans + (arr1[i] * arr2[i]);
    }

    *result = ans;
}


int main() {
    const size_t N = 1 << 28;
    const size_t ARRAY_BYTES = N * sizeof(double);

    printf("Array size: %zu\n\n", N);

    clock_t begin, end;

    double time_taken_c;
    double average_time_c;
    double time_taken_asm;
    double average_time_asm;

    double* array1;
    double* array2;
    double* sdotc;
    double* sdotasm;

    array1 = (double*)malloc(N * sizeof(double));
    array2 = (double*)malloc(N * sizeof(double));
    sdotc = (double*)malloc(N * sizeof(double));
    sdotasm = (double*)malloc(N * sizeof(double));

    int i;
    for (i = 0; i < N; i++) {
        array1[i] = 6.0000000000123456;
        array2[i] = 3.0000000000005157;
    }
    int loop = 30;
    int j;

    printf("C Function:\n\n");
    dotProduct(N, &sdotc[0], array1, array2);


    begin = clock();

    for (j = 0; j < loop; j++) {
        dotProduct(N, &sdotc[j], array1, array2);
    }
    end = clock();

    time_taken_c = ((double)(end - begin)) * 1e3 / CLOCKS_PER_SEC;
    average_time_c = time_taken_c / loop;
    int error = 0;
    for (j = 0; j < loop - 1; j++) {
        if (sdotc[j] != sdotc[j + 1]) {
            error += 1;
        };
    }
    if (error == 0) {
        printf("C function works properly as no errors are found\n");
    }
    else {
        printf("C function has %d errors\n", error);
    }

    printf("C functions take %lf milliseconds for array size %zu \n", average_time_c, N);
    printf("Dot Product is %.20lf\n\n", sdotc[0]);
    printf("Assembly Function:\n\n");

    // -------------x86-64-------------
    dotProductx64(N, &sdotasm[0], array1, array2);

    int loop2 = 30;
    int k;

    begin = clock();
    for (int k = 0; k < loop2; k++) {
        dotProductx64(N, &sdotasm[k], array1, array2);
    }
    end = clock();

    time_taken_asm = ((double)(end - begin)) * 1e3 / CLOCKS_PER_SEC;
    average_time_asm = time_taken_asm / loop2;

    int error2 = 0;
    for (j = 0; j < loop - 1; j++) {
        if (sdotc[j] != sdotasm[j]) {
            error2 += 1;
        };
    }
    if (error == 0) {
        printf("Assembly function works properly as it outputs the same as C function\n");
    }
    else {
        printf("C function has %d errors\n", error);
    }

    printf("Assembly functions takes %.2lf milliseconds for array size %zu \n", average_time_asm, N);
    printf("Dot Product is %.20lf\n\n", sdotasm[0]);

    //Comparisons
    printf("Comparisons:\n");
    printf("\nOutputs C dotproduct and Assembly dotproduct are ");
    if (sdotc[0] == sdotasm[0])
        printf("equivalent\n\n");
    else
        printf("not equivalent\n\n");
    printf("For loop count of %d, Average Execution Time for array size %zu is as follows:\n\n", loop, N);
    printf("C: %lf ms \n", average_time_c);
    printf("Assembly: %lf ms \n\n", average_time_asm);

    if (average_time_c > average_time_asm) {
        double percent_slower = ((average_time_c - average_time_asm) / average_time_c) * 100.0;
        printf("Assembly is faster by %.2lf%%\n", percent_slower);
    }
    else if (average_time_asm > average_time_c) {
        double percent_slower = ((average_time_asm - average_time_c) / average_time_asm) * 100.0;
        printf("C is faster by %.2lf%%\n", percent_slower);
    }
    else {
        printf("Both C and Assembly took the same time.\n");
    }

    return 0;

}
