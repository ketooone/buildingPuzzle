#include "flags.h"
#include "fields.h"
#include <stdio.h>

void method2(field *field, flag *flag){
    // int numcnt = 0;
    for (int i = 0; i < field->n * field->n; i++){
        if (field->num[i / field->n][i % field->n] == field->n){
            if (i / field->n == 0){
                for (int j = 0; j < field->n; j++){
                    if (field->matrix[j][i % field->n] == 0){
                        field->matrix[j][i % field->n] = j + 1;
                        // numcnt++;
                    }
                }
            } else if (i / field->n == 1){
                for (int j = 0; j < field->n; j++){
                    if (field->matrix[field->n - j - 1][i % field->n] == 0){
                        field->matrix[field->n - j - 1][i % field->n] = j + 1;
                        // numcnt++;
                    }
                }
            } else if (i / field->n == 2){
                for (int j = 0; j < field->n; j++){
                    if (field->matrix[i % field->n][j] == 0){
                        field->matrix[i % field->n][j] = j + 1;
                        // numcnt++;
                    }
                }
            } else if (i / field->n == 3){
                for (int j = 0; j < field->n; j++){
                    if (field->matrix[i % field->n][field->n - j - 1] == 0){
                        field->matrix[i % field->n][field->n - j - 1] = j + 1;
                        // numcnt++;
                    }
                }
            }
        }
    }
}
