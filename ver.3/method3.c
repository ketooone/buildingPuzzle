#include "flags.h"
#include "fields.h"
#include <stdio.h>
#include <stdlib.h>

//todo numcnt加える
void method3(field *field, flag *flag){
    int *count = (int *)malloc(sizeof(int) * field->n);
    for (int i = 0; i < field->n; i++){
        count[i] = 0;
    }
    int col;
    int row;

    for (int i = 0; i < field->n * field->n; i++){
        if (field->matrix[i / field->n][i % field->n] != 0){
            count[field->matrix[i / field->n][i % field->n] - 1]++;
        }
    }
    for (int i = 0; i < field->n; i++){
        if (count[i] == field->n - 1){
            for (int j = 0; j < field->n; j++){
                int col_cnt = 0;
                int row_cnt = 0;
                for (int k = 0; k < field->n; k++){
                    if (field->matrix[j][k] == i + 1){
                        row_cnt++;
                    }
                    if (field->matrix[k][j] == i + 1){
                        col_cnt++;
                    }
                }
                if (row_cnt == 0){
                    row = j;
                }
                if (col_cnt == 0){
                    col = j;
                }
            }
            field->matrix[row][col] = i + 1;
        }
    }
}
