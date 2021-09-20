#include <stdlib.h>

int **init_matrix(int **matrix, int n){
    matrix = (int **)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++){
        matrix[i] = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++){
            matrix[i][j] = 0;
        }
    }
    return (matrix);
}