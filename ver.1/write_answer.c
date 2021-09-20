#include <stdio.h>

void write_answer(int **matrix, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d", matrix[i][j]);
            if (j == n - 1){
                printf("\n");
            } else {
                printf(" ");
            }
        }
    }
}