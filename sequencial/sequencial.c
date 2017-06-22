#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include <matrix.h>


double* jacobi_method(Matrix *a, double *b, double *x, int dimension, double error);
double* jacobi_interator(Matrix *a, double *b, double *x, int dimension);
void output_gen(char *file_path, double exec_time, double *x, int dimension);

//argv[1] = arquivo de entrada; argv[2] = arquivo de saída; argv[3] = potencia do erro;

void main(int argc, char *argv[]) {
	Matrix *a;
    double *b, *x, *xk;
    int dimension;
    int i, j;
    clock_t begin, end;
    
    dimension = matrix_read_linear_system(argv[1], &a, &b);
    x = (double *)malloc(dimension * sizeof(double));
    for(i = 0; i < dimension; i++) x[i] = 0.0;
    begin = clock();
    x = jacobi_method(a, b, x, dimension, pow(10, (int)strtol(argv[3], NULL, 10)));
    end = clock();
    output_gen(argv[2], (double)(end-begin)/CLOCKS_PER_SEC, x, dimension);
    for(i = 0; i < dimension; i++) printf("x[%d]: %1.10e\n", i+1, x[i]);
}

double* jacobi_method(Matrix *a, double *b, double *x, int dimension, double error) {
    double *xk;
    int i, j = 0;
    xk = jacobi_interator(a, b, x, dimension);
    while(fabs(xk[0] - x[0]) >= error) {
        if(!(j%2)) x = jacobi_interator(a, b, xk, dimension);
        else xk = jacobi_interator(a, b, x, dimension);
        j++;
    }
    
    return xk;
}

double* jacobi_interator(Matrix *a, double *b, double *x, int dimension) {
    int i, j;
    double *xk = (double *)malloc(dimension * sizeof(double));
    for(i = 0; i < dimension; i++) {
        xk[i] = 0;
        for(j = 0; j < dimension; j++) {
            if(i == j) continue;
            xk[i] += matrix_get(a, i, j) *x[j];
        }
        xk[i] = ((double)1/matrix_get(a, i, i))*(b[i] - xk[i]);
    }
    
    return xk;
}

void output_gen(char *file_path, double exec_time, double *x, int dimension) {
    FILE *fp;
    int i;
    
    printf("Generating output file...\n");
    fp = fopen(file_path, "w");
    fprintf(fp, "%1.10e\n", exec_time);
    fprintf(fp, "x[0]: 0.0\n");
    for(i = 0; i < dimension; i++) fprintf(fp, "x[%d]: %1.10e\n", i+1, x[i]);
    fclose(fp);
}
