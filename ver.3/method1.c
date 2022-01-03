#include "flags.h"
#include "fields.h"
#include <stdio.h>

void method1(field *field, flag *flag){
    int numcnt = 0;
    for (int i = 0; i < field->n * field->n; i++){
        if (field->num[i / field->n][i % field->n] == 1){
            if (i / field->n == 0){
                field->matrix[i / field->n][i % field->n] = field->n;
                numcnt++;
            } else if (i / field->n == 1){
                field->matrix[field->n - 1][i % field->n] = field->n;
                numcnt++;
            } else if (i / field->n == 2){
                field->matrix[i % field->n][0] = field->n;
                numcnt++;
            } else if (i / field->n == 3){
                field->matrix[i % field->n][field->n - 1] = field->n;
                numcnt++;
            }
        }
    }
}
