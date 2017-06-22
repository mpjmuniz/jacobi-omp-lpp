#include<stdio.h>
#include <stdlib.h>

void main(int argc, char **argv) {
	//argv[1] = caminho + nome do arquivo; argv[2] = tamanho do sistema
    FILE *fp;
    int dimension = strtol(argv[2], NULL, 10);
    char *path_file = argv[1];
    int i, j;
    
    fp = fopen(path_file, "w");
    fprintf(fp, "%d\n", dimension);
    for(i = 0; i < dimension; i++) {
        for(j = 0; j < dimension; j++) {
            if(i == j) fprintf(fp, "%d ", 4);
            else if(abs(j - i) == 1) fprintf(fp, "%d ", -1);
            else fprintf(fp, "%d ", 0);
        }
        fprintf(fp, "\n");
    }
    for(i = 1; i < dimension+1; i++) fprintf(fp, "%d\n", i);
    fclose(fp);
}
