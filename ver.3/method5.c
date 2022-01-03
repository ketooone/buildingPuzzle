#include "flags.h"
#include "fields.h"
#include <stdio.h>
#include <stdlib.h>

int count_colup(int cu, int n, int **matrix);
int count_coldown(int cd, int n, int **matrix);
int count_rowleft(int rl, int n, int **matrix);
int count_rowright(int rr, int n, int **matrix);

//todo numcnt

//並び替え
int next_permutation(int *arr, int len) {
    int left = len - 2;
    while (left >= 0 && arr[left] >= arr[left + 1]){
        left--;
    }
    if (left < 0){
        return 0;
    }
    int right = len - 1;
    while (arr[left] >= arr[right]) right--;
    { int t = arr[left]; arr[left] = arr[right]; arr[right] = t; }
        left++;
        right = len - 1;
    while (left < right) {
    { int t = arr[left]; arr[left] = arr[right]; arr[right] = t; }
        left++;
        right--;
    }
    return 1;
}

int judgement(int *judge, int n){
    int cnt = 0;
    int pre = 0;
    for (int i = 0; i < n; i++){
        if (pre < judge[i]){
            pre = judge[i];
            cnt++;
        }
    }
    return (cnt);
}

void method5(field *field, flag *flag){
    int *arr = (int *)malloc(sizeof(int) * field->n);
    int *judge = (int *)malloc(sizeof(int) * field->n);
    int *tmp = (int *)malloc(sizeof(int) * field->n);
    int len;
    int count;
    int cnt_flag;
    int matrix_flag;
    int repeatcnt;

    do {
        repeatcnt = 0;
        for (int i = 0; i < field->n * field->n; i++){
            flag->arrflag = 0;
            flag->placeflag = 0;
            count = 0;
            cnt_flag = 0;
            matrix_flag = 0;
            len = field->n;
            for (int j = 0; j < field->n; j++){
                arr[j] = 0;
                judge[j] = 0;
                tmp[j] = 0;
            }
            if (i / field->n == 0){
                for (int j = 0; j < field->n; j++){
                    if (field->matrix[j][i % field->n] != 0){
                        count++;
                        flag->arrflag += (1 << (field->matrix[j][i % field->n] - 1));
                        flag->placeflag += (1 << j);
                    }
                }
            } else if (i / field->n == 1){
                for (int j = 0; j < field->n; j++){
                    if (field->matrix[field->n - j - 1][i % field->n] != 0){
                        count++;
                        flag->arrflag += (1 << (field->matrix[field->n - j - 1][i % field->n] - 1));
                        flag->placeflag += (1 << j);
                    }
                }
            } else if (i / field->n == 2){
                for (int j = 0; j < field->n; j++){
                    if (field->matrix[i % field->n][j] != 0){
                        count++;
                        flag->arrflag += (1 << (field->matrix[i % field->n][j] - 1));
                        flag->placeflag += (1 << j);
                    }
                }
            } else if (i / field->n == 3){
                for (int j = 0; j < field->n; j++){
                    if (field->matrix[i % field->n][field->n - j - 1] != 0){
                        count++;
                        flag->arrflag += (1 << (field->matrix[i % field->n][field->n - j - 1] - 1));
                        flag->placeflag += (1 << j);
                    }
                }
            }
            if (count != field->n){
                len = len - count;
                int j = 0;
                for (int k = 0; k < field->n; k++){
                    if (((flag->arrflag >> k) & 1) == 0){
                        arr[j] = k + 1;
                        j++;
                    }
                }

                do {
                    int k = 0;
                    matrix_flag = 0;
                    if (i / field->n == 0){
                        for (int j = 0; j < field->n; j++){
                            if ((flag->placeflag >> j) & 1){
                                judge[j] = field->matrix[j][i % field->n];
                            } else {
                                judge[j] = arr[k];
                                k++;
                            }
                        }
                        for (int j = 0; j < field->n; j++){
                            for (int k = 0; k < field->n; k++){
                                if (judge[j] == field->matrix[j][k] && k != i % field->n){
                                    matrix_flag++;
                                }
                            }
                        }
                        if (field->num[i / field->n][i % field->n] == 0 && matrix_flag == 0){
                            for (int j = 0; j < field->n; j++){
                                tmp[j] = judge[j];
                            }
                            cnt_flag++;
                        } else if (judgement(judge, field->n) == field->num[i / field->n][i % field->n] && matrix_flag == 0){
                            for (int j = 0; j < field->n; j++){
                                tmp[j] = judge[j];
                            }
                            cnt_flag++;
                        }
                    } else if (i / field->n == 1){
                        for (int j = 0; j < field->n; j++){
                            if ((flag->placeflag >> j) & 1){
                                judge[j] = field->matrix[field->n - j - 1][i % field->n];
                            } else {
                                judge[j] = arr[k];
                                k++;
                            }
                        }
                        for (int j = 0; j < field->n; j++){
                            for (int k = 0; k < field->n; k++){
                                if (judge[j] == field->matrix[field->n - j - 1][k] && k != i % field->n){
                                    matrix_flag++;
                                }
                            }
                        }
                        if (field->num[i / field->n][i % field->n] == 0 && matrix_flag == 0){
                            for (int j = 0; j < field->n; j++){
                                tmp[j] = judge[j];
                            }
                            cnt_flag++;
                        } else if (judgement(judge, field->n) == field->num[i / field->n][i % field->n] && matrix_flag == 0){
                            for (int j = 0; j < field->n; j++){
                                tmp[j] = judge[j];
                            }
                            cnt_flag++;
                        }
                    } else if (i / field->n == 2){
                        for (int j = 0; j < field->n; j++){
                            if ((flag->placeflag >> j) & 1){
                                judge[j] = field->matrix[i % field->n][j];
                            } else {
                                judge[j] = arr[k];
                                k++;
                            }
                        }
                        for (int j = 0; j < field->n; j++){
                            for (int k = 0; k < field->n; k++){
                                if (judge[j] == field->matrix[k][j] && k != i % field->n){
                                    matrix_flag++;
                                }
                            }
                        }
                        if (field->num[i / field->n][i % field->n] == 0 && matrix_flag == 0){
                            for (int j = 0; j < field->n; j++){
                                tmp[j] = judge[j];
                            }
                            cnt_flag++;
                        } else if (judgement(judge, field->n) == field->num[i / field->n][i % field->n] && matrix_flag == 0){
                            for (int j = 0; j < field->n; j++){
                                tmp[j] = judge[j];
                            }
                            cnt_flag++;
                        }
                    } else if (i / field->n == 3){
                        for (int j = 0; j < field->n; j++){
                            if ((flag->placeflag >> j) & 1){
                                judge[j] = field->matrix[i % field->n][field->n - j - 1];
                            } else {
                                judge[j] = arr[k];
                                k++;
                            }
                        }
                        for (int j = 0; j < field->n; j++){
                            for (int k = 0; k < field->n; k++){
                                if (judge[j] == field->matrix[k][field->n - j - 1] && k != i % field->n){
                                    matrix_flag++;
                                }
                            }
                        }
                        if (field->num[i / field->n][i % field->n] == 0 && matrix_flag == 0){
                            for (int j = 0; j < field->n; j++){
                                tmp[j] = judge[j];
                            }
                            cnt_flag++;
                        } else if (judgement(judge, field->n) == field->num[i / field->n][i % field->n] && matrix_flag == 0){
                            for (int j = 0; j < field->n; j++){
                                tmp[j] = judge[j];
                            }
                            cnt_flag++;
                        }
                    }
                } while (next_permutation(arr, len));
                if (cnt_flag == 1){
                    if (i / field->n == 0){
                        for (int j = 0; j < field->n; j++){
                            field->matrix[j][i % field->n] = tmp[j];
                        }
                    } else if (i / field->n == 1){
                        for (int j = 0; j < field->n; j++){
                            field->matrix[field->n - j - 1][i % field->n] = tmp[j];
                        }
                    } else if (i / field->n == 2){
                        for (int j = 0; j < field->n; j++){
                            field->matrix[i % field->n][j] = tmp[j];
                        }
                    } else if (i / field->n == 3){
                        for (int j = 0; j < field->n; j++){
                        field->matrix[i % field->n][field->n - j - 1] = tmp[j];
                        }
                    }
                    repeatcnt = 1;
                }
            }
        } 
    } while (repeatcnt == 1);
}