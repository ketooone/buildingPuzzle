#include <stdio.h>
#include "fields.h"

void write_answer(field *field){
    printf("  |");
    for (int i = 0; i < field->n; i++){
        printf("%d", field->num[0][i]);
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
        printf("%d |",field->num[2][i]);
        for (int j = 0; j < field->n; j++){
            printf("%d", field->matrix[i][j]);
            if (j == field->n - 1){
                printf("| %d\n",field->num[3][i]);
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
        printf("%d", field->num[1][i]);
        if (i != field->n - 1){
            printf(" ");
        }
    }
    printf("|\n");
}