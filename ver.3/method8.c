#include "flags.h"
#include "fields.h"
#include <stdio.h>
#include <stdlib.h>

void method3(field *field, flag *flag);
void method4(field *field, flag *flag);

//入らない数字のフラグを立てていく
void method8(field *field, flag *flag){
    int repeatcnt;
    int diff;
    int cnt;
    int tmp;

    for (int i = 0; i < field->n; i++){
        for (int j = 0; j < field->n; j++){
            if (field->matrix[i][j] != 0){ 
                for (int k = 0; k < field->n; k++){
                    if ((flag->rflag[i * field->n + k] >> (field->matrix[i][j] - 1) & 1) == 0){ //列を探索
                        flag->rflag[i * field->n + k] += (1 << (field->matrix[i][j] - 1));
                    }
                    if ((flag->rflag[k * field->n + j] >> (field->matrix[i][j] - 1) & 1) == 0){ //行を探索
                        flag->rflag[k * field->n + j] += (1 << (field->matrix[i][j] - 1));
                    }
                }
            }
            if (field->num[0][j] != 0){ //上のヒント数字
                diff = i + 1;
                for (int k = 0; k < field->num[0][j] - diff; k++){ //todo
                    if ((flag->rflag[i * field->n + j] >> (field->n - k - 1) & 1) == 0){
                        flag->rflag[i * field->n + j] += (1 << (field->n - k - 1));
                    }
                }
            }
            if (field->num[1][j] != 0){ //下のヒント数字
                diff = field->n - i;
                for (int k = 0; k < field->num[1][j] - diff; k++){
                    if ((flag->rflag[i * field->n + j] >> (field->n - k - 1) & 1) == 0){
                        flag->rflag[i * field->n + j] += (1 << (field->n - k - 1));
                    }
                }
            }
            if (field->num[2][i] != 0){ //左のヒント数字
                diff = j + 1;
                for (int k = 0; k < field->num[2][i] - diff; k++){
                    if ((flag->rflag[i * field->n + j] >> (field->n - k - 1) & 1) == 0){
                        flag->rflag[i * field->n + j] += (1 << (field->n - k - 1));
                    }
                }
            }
            if (field->num[3][i] != 0){ //右のヒント数字
                diff = field->n - j;
                for (int k = 0; k < field->num[3][i] - diff; k++){
                    if ((flag->rflag[i * field->n + j] >> (field->n - k - 1) & 1) == 0){
                        flag->rflag[i * field->n + j] += (1 << (field->n - k - 1));
                    }
                }
            }
        }
    } //フラグ立てここまで
    for (int i = 0; i < field->n; i++){
        for (int j = 0; j < field->n; j++){
            cnt = 0;
            tmp = 0;
            for (int k = 0; k < field->n; k++){
                if ((flag->rflag[i * field->n + j] >> k & 1) == 0){
                    cnt++;
                    tmp = k;
                }
            }
            if (cnt == 1){ //候補数字が一つのみのときに数字を確定
                field->matrix[i][j] = tmp + 1;
                for (int k = 0; k < field->n; k++){
                    if ((flag->rflag[i * field->n + k] >> tmp & 1) == 0){
                        flag->rflag[i * field->n + k] += (1 << tmp);
                    }
                    if ((flag->rflag[k * field->n + j] >> tmp & 1) == 0){
                        flag->rflag[k * field->n + j] += (1 << tmp);
                    }
                }  
            }
        }
    }
    do {
        repeatcnt = 0;
        for (int i = 0; i < field->n; i++){ //行探索を縦列繰り返す
            for (int j = 0; j < field->n; j++){ //数探索
                cnt = 0;
                tmp = 0;
                for (int k = 0; k < field->n; k++){ //ヨコに動かす
                    if ((flag->rflag[k + i * field->n] >> j & 1) == 0){
                        cnt++;
                        tmp = k;
                    }
                }
                if (cnt == 1){
                    if (field->matrix[i][tmp] == 0){
                        field->matrix[i][tmp] = j + 1;
                        repeatcnt = 1;
                    }
                    for (int l = 0; l < field->n; l++){
                        if ((flag->rflag[tmp + l * field->n] >> j & 1) == 0){
                            flag->rflag[tmp + l * field->n] += (1 << j); //新たに数字が埋まった分flagを立てる
                        }
                    }
                }
            }
        }
        for (int i = 0; i < field->n; i++){ //列探索を横列繰り返す
            for (int j = 0; j < field->n; j++){ //数探索
                cnt = 0;
                tmp = 0;
                for (int k = 0; k < field->n; k++){ //タテに動かす
                    if ((flag->rflag[i + k * field->n] >> j & 1) == 0){
                        cnt++;
                        tmp = k;
                    }
                }
                if (cnt == 1){
                    if (field->matrix[tmp][i] == 0){
                        field->matrix[tmp][i] = j + 1;
                        repeatcnt = 1;
                    }
                    for (int l = 0; l < field->n; l++){
                        if ((flag->rflag[l + tmp * field->n] >> j & 1) == 0){
                            flag->rflag[l + tmp * field->n] += (1 << j);
                        }
                    }
                }
            }
        }
        method3(field, flag);
        method4(field, flag);
    } while (repeatcnt == 1);
}
