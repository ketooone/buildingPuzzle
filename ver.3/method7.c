#include "flags.h"
#include "fields.h"
#include <stdio.h>
#include <stdlib.h>

//todo 101 右側条件２がうまくいかない
void method7(field *field, flag *flag){
    int cnt;
    int pre;
    int repeatcnt;
    int zero_flag;
    int max;

    do{
        repeatcnt = 0;
        for (int i = 0; i < field->n * field->n; i++){
            if (1 < field->num[i / field->n][i % field->n] && field->num[i / field->n][i % field->n] < field->n){
                cnt = 0;
                pre = 0;
                zero_flag = 0;
                max = 0;
                flag->arrflag = 0;
                flag->placeflag = 0;
                if (i / field->n == 0){ //上
                    for (int j = 0; j < field->n; j++){
                        if (field->matrix[j][i % field->n] != 0){
                            flag->arrflag += (1 << (field->matrix[j][i % field->n] - 1));
                            flag->placeflag += (1 << j);
                        }
                        if (pre < field->matrix[j][i % field->n]){
                            pre = field->matrix[j][i % field->n];
                            cnt++;
                        }
                    }
                    if (cnt == field->num[i / field->n][i % field->n] - 1){
                        if (field->matrix[0][i % field->n] == 0){ //条件１
                            for (int j = 0; j < field->n; j++){
                                if ((flag->placeflag >> field->n - j - 1) & 1 == 0){
                                    zero_flag = 1;
                                }
                                if ((zero_flag == 1 && flag->placeflag >> field->n - j - 1) & 1 == 1){
                                    break;
                                }
                                if (j == field->n - 1){
                                    for (int k = 0; k < field->n; k++){
                                        if ((flag->arrflag >> field->n - k - 1) & 1 == 0){
                                            field->matrix[0][i % field->n] == field->n - k;
                                            repeatcnt = 1;
                                            break;
                                        }
                                    }
                                }
                            }
                        } else { //条件２
                            for (int j = 0; j < field->n; j++){
                                if (field->matrix[j][i % field->n] == 0){
                                    for (int k = 0; k < field->n; k++){
                                        if ((flag->arrflag >> field->n - k - 1) & 1 == 0 && k <= max){
                                            field->matrix[j][i % field->n] == field->n - k;
                                            repeatcnt = 1;
                                            break;
                                        } else {
                                            if (max < field->matrix[j][i % field->n]){
                                                max = field->matrix[j][i % field->n];
                                            }
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                    }
                } else if (i / field->n == 1){
                    for (int j = 0; j < field->n; j++){
                        if (field->matrix[field->n - j - 1][i % field->n] != 0){
                            flag->arrflag += (1 << (field->matrix[field->n - j - 1][i % field->n] - 1));
                            flag->placeflag += (1 << j);
                        }
                        if (pre < field->matrix[field->n - j - 1][i % field->n]){
                            pre = field->matrix[field->n - j - 1][i % field->n];
                            cnt++;
                        }
                    }
                    if (cnt == field->num[i / field->n][i % field->n] - 1){
                        if (field->matrix[field->n - 1][i % field->n] == 0){ //条件１
                            for (int j = 0; j < field->n; j++){
                                if ((flag->placeflag >> field->n - j - 1) & 1 == 0){
                                    zero_flag = 1;
                                }
                                if ((zero_flag == 1 && flag->placeflag >> field->n - j - 1) & 1 == 1){
                                    break;
                                }
                                if (j == field->n - 1){
                                    for (int k = 0; k < field->n; k++){
                                        if ((flag->arrflag >> field->n - k - 1) & 1 == 0){
                                            field->matrix[field->n - 1][i % field->n] == field->n - k;
                                            repeatcnt = 1;
                                            break;
                                        }
                                    }
                                }
                            }
                        } else { //条件２
                            for (int j = 0; j < field->n; j++){
                                if (field->matrix[field->n - j - 1][i % field->n] == 0){
                                    for (int k = 0; k < field->n; k++){
                                        if ((flag->arrflag >> field->n - k - 1) & 1 == 0 && k <= max){
                                            field->matrix[field->n - j - 1][i % field->n] == field->n - k;
                                            repeatcnt = 1;
                                            break;
                                        } else {
                                            if (max < field->matrix[field->n - j - 1][i % field->n]){
                                                max = field->matrix[field->n - j - 1][i % field->n];
                                            }
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                    }
                } else if (i / field->n == 2){
                    for (int j = 0; j < field->n; j++){
                        if (field->matrix[i % field->n][j] != 0){
                            flag->arrflag += (1 << (field->matrix[i % field->n][j] - 1));
                            flag->placeflag += (1 << j);
                        }
                        if (pre < field->matrix[i % field->n][j]){
                            pre = field->matrix[i % field->n][j];
                            cnt++;
                        }
                    }
                    if (cnt == field->num[i / field->n][i % field->n] - 1){
                        if (field->matrix[i % field->n][0] == 0){ //条件１
                            for (int j = 0; j < field->n; j++){
                                if ((flag->placeflag >> field->n - j - 1) & 1 == 0){
                                    zero_flag = 1;
                                }
                                if ((zero_flag == 1 && flag->placeflag >> field->n - j - 1) & 1 == 1){
                                    break;
                                }
                                if (j == field->n - 1){
                                    for (int k = 0; k < field->n; k++){
                                        if ((flag->arrflag >> field->n - k - 1) & 1 == 0){
                                            field->matrix[i % field->n][0] == field->n - k;
                                            repeatcnt = 1;
                                            break;
                                        }
                                    }
                                }
                            }
                        } else { //条件２
                            for (int j = 0; j < field->n; j++){
                                if (field->matrix[i % field->n][j] == 0){
                                    for (int k = 0; k < field->n; k++){
                                        if ((flag->arrflag >> field->n - k - 1) & 1 == 0 && k <= max){
                                            field->matrix[i % field->n][j] == field->n - k;
                                            repeatcnt = 1;
                                            break;
                                        } else {
                                            if (max < field->matrix[i % field->n][j]){
                                                max = field->matrix[i % field->n][j];
                                            }
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                    }
                } else {
                    for (int j = 0; j < field->n; j++){
                        if (field->matrix[i % field->n][field->n - j - 1] != 0){
                            flag->arrflag += (1 << (field->matrix[i % field->n][field->n - j - 1] - 1));
                            flag->placeflag += (1 << j);
                        }
                        if (pre < field->matrix[i % field->n][field->n - j - 1]){
                            pre = field->matrix[i % field->n][field->n - j - 1];
                            cnt++;
                        }
                    }
                    if (cnt == field->num[i / field->n][i % field->n] - 1){
                        if (field->matrix[i % field->n][field->n - 1] == 0){ //条件１
                            for (int j = 0; j < field->n; j++){
                                if ((flag->placeflag >> field->n - j - 1) & 1 == 0){
                                    zero_flag = 1;
                                }
                                if ((zero_flag == 1 && flag->placeflag >> field->n - j - 1) & 1 == 1){
                                    break;
                                }
                                if (j == field->n - 1){
                                    for (int k = 0; k < field->n; k++){
                                        if ((flag->arrflag >> field->n - k - 1) & 1 == 0){
                                            field->matrix[i % field->n][field->n - 1] == field->n - k;
                                            repeatcnt = 1;
                                            break;
                                        }
                                    }
                                }
                            }
                        } else { //条件２
                            for (int j = 0; j < field->n; j++){
                                if (field->matrix[i % field->n][field->n - j - 1] == 0){
                                    for (int k = 0; k < field->n; k++){
                                        if ((flag->arrflag >> field->n - k - 1) & 1 == 0){
                                            field->matrix[i % field->n][field->n - j - 1] == field->n - k;
                                            repeatcnt = 1;
                                            break;
                                        } else {
                                            if (max < field->matrix[i % field->n][field->n - j - 1]){
                                                max = field->matrix[i % field->n][field->n - j - 1];
                                            }
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    } while (repeatcnt == 1);
}
