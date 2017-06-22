#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

Matrix *matrix_allocate(int dim){
	Matrix *output = malloc(sizeof(Matrix));
	output->values = malloc(sizeof(double) * dim * dim);
	output->dim = dim;

	if(!output || !(output->values)){
		fprintf(stderr, "Erro na alocação de memória\n");
	}

	return output;
}

int matrix_read_linear_system(char *file_path, Matrix **a, double **b){
	FILE *fp;
	int dimension;
	int i, j;

    fp = fopen(file_path, "r");
    
    fscanf(fp, "%d", &dimension);
    
	*a = matrix_allocate(dimension);
    
    *b = (double *)malloc(dimension * sizeof(double));
    
    for(i = 0; i < dimension; i++)
        for(j = 0; j < dimension; j++)
            if(!fscanf(fp, "%lf", &matrix_get(*a, i, j))) break;
            
    for(i = 0; i < dimension; i++)
        if(!fscanf(fp, "%lf", &(*b)[i])) break;
    
    fclose(fp);

	return dimension;
}

void matrix_free(Matrix *matrix){
	if(matrix){
		free(matrix->values);
		free(matrix);
	}
}
