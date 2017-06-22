#ifndef __matrix_h__
#define __matrix_h__

/* implementação de Matriz quadrada de ordem n em um vetor*/

typedef struct matrix {
	int dim;
	double *values;
} Matrix;

Matrix *matrix_allocate(int dim);

int matrix_read_linear_system(char *file_path, Matrix **a, double **b);

void matrix_free(Matrix *matrix);

// define o elemento na linha L, coluna C como sendo V, na matrix M
#define matrix_set(M, L, C, V) ((M)->values[matrix_index(M, L, C)] = V)

// obtem o elemento na linha L, coluna C, da matrix M
#define matrix_get(M, L, C) ((M)->values[matrix_index(M, L, C)])

// obtem o indice físico relativo ao indice logico da linha L, coluna C
#define matrix_index(M, L, C) (((M)->dim * L) + C)

#endif
