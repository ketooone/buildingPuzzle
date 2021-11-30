#include <stdio.h>
#include "fields.h"

/*void write_answer(int **matrix, int n){
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
}*/

void write_answer(field *field){
    printf("  |");
    for (int i = 0; i < field->n; i++){
        if (field->num[0][i] != 0){
            printf("%d", field->num[0][i]);
        } else {
            printf(" ");
        }
        if (i != field->n - 1){
            printf(" ");
        }
    }
    printf("|\n--+");

    for (int i = 0; i < field->n * 2 - 1; i++){
        printf("-");
    }
    printf("+--\n");
    for (int i = 0; i < field->n; i++){
        if (field->num[2][i] != 0){
            printf("%d |", field->num[2][i]);
        } else {
            printf("  |");
        }
        for (int j = 0; j < field->n; j++){
            if (field->matrix[i][j] != 0){
                printf("%d", field->matrix[i][j]);
            } else {
                printf(" ");
            }
            if (j == field->n - 1){
                if (field->num[3][i] != 0){
                    printf("| %d\n", field->num[3][i]);
                } else {
                    printf("|\n");
                }
            } else {
                printf(" ");
            }
        }
    }
    printf("--+");
    for (int i = 0; i < field->n * 2 - 1; i++){
        printf("-");
    }
    printf("+--\n");
    printf("  |");
    for (int i = 0; i < field->n; i++){
        if (field->num[1][i] != 0){
            printf("%d", field->num[1][i]);
        } else {
            printf(" ");
        }
        if (i != field->n - 1){
            printf(" ");
        }
    }
    printf("|\n\n");
}