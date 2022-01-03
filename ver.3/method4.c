#include "flags.h"
#include "fields.h"
#include <stdio.h>
#include <stdlib.h>

//todo numcnt
void method4(field *field, flag *flag){
    int count;

    for (int i = 0; i < field->n; i++){
        //行
        flag->arrflag = 0;
        flag->placeflag = 0;
        count = 0;
        for (int j = 0; j < field->n; j++){
            if (field->matrix[i][j] != 0){
                flag->arrflag += (1 << (field->matrix[i][j] - 1));
                flag->placeflag += (1 << j);
                count++;
            }
        }
        if (count == field->n - 1){
            for (int j = 0; j < field->n; j++){
                if (((flag->placeflag >> j) & 1) == 0){
                    for (int k = 0; k < field->n; k++){
                        if (((flag->arrflag >> k) & 1) == 0){
                            field->matrix[i][j] = k + 1;
                        }
                    }
                }
            }
        }
        //列
        flag->arrflag = 0;
        flag->placeflag = 0;
        count = 0;
        for (int j = 0; j < field->n; j++){
            if (field->matrix[j][i] != 0){
                flag->arrflag += (1 << (field->matrix[j][i] - 1));
                flag->placeflag += (1 << j);
                count++;
            }
        }
        if (count == field->n - 1){
            for (int j = 0; j < field->n; j++){
                if (((flag->placeflag >> j) & 1) == 0){
                    for (int k = 0; k < field->n; k++){
                        if (((flag->arrflag >> k) & 1) == 0){
                            field->matrix[j][i] = k + 1;
                        }
                    }
                }
            }
        }
    }
}
