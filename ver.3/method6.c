#include "flags.h"
#include "fields.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

void method6(field *field, flag *flag){
    int subcnt;
    int cnt;
    int placecnt;
    int ktmp;
    int placenum;
    int start;
    int repeatcnt;

    do{
        repeatcnt = 0;
        for (int i = 0; i < field->n * field->n; i++){
            if (1 < field->num[i / field->n][i % field->n] && field->num[i / field->n][i % field->n] < field->n){
                start = field->n - field->num[i / field->n][i % field->n] + 2;
                placenum = field->n - 1; //探索行数　-1 づつ減らしていく
                for (int j = start; j <= field->n; j++){ //ビルの高さを順に探索
                    // printf("j:%d\n",j);
                    cnt = 0;
                    subcnt = 0;
                    ktmp = 0;
                    if (i / field->n == 0){ //ヒント数字が上の場合
                        for (int k = 0; k < placenum; k++){ //見るべき列の個数
                            subcnt = 0;
                            for (int l = 0; l < field->n; l++){ //行の個数
                                if (field->matrix[field->n - k - 1][l] != j){
                                    subcnt++;
                                }
                                if (field->matrix[l][i % field->n] == j){
                                    cnt = 10000;
                                }
                            }
                            if (subcnt == field->n && field->matrix[field->n - k - 1][i % field->n] == 0){
                                cnt++;
                                ktmp = field->n - k - 1;
                            }
                        }
                        if (cnt == 1){
                            field->matrix[ktmp][i % field->n] = j;
                            repeatcnt = 1;
                        }
                    } else if (i / field->n == 1){ //下の場合
                        for (int k = 0; k < placenum; k++){
                            subcnt = 0;
                            for (int l = 0; l < field->n; l++){
                                if (field->matrix[k][l] != j){
                                    subcnt++;
                                }
                                if (field->matrix[l][i % field->n] == j){
                                    cnt = 10000;
                                }
                            }
                            if (subcnt == field->n && field->matrix[k][i % field->n] == 0){
                                cnt++;
                                ktmp = k;
                            }
                        }
                        if (cnt == 1){
                            field->matrix[ktmp][i % field->n] = j;
                            repeatcnt = 1;
                        }
                    } else if (i / field->n == 2){ //左の場合
                        for (int k = 0; k < placenum; k++){
                            subcnt = 0;
                            for (int l = 0; l < field->n; l++){
                                if (field->matrix[l][field->n - k - 1] != j){
                                    subcnt++;
                                }
                                if (field->matrix[i % field->n][l] == j){
                                    cnt = 10000;
                                }
                            }
                            if (subcnt == field->n && field->matrix[i % field->n][field->n - k - 1] == 0){
                                cnt++;
                                ktmp = field->n - k - 1;
                            }
                        }
                        if (cnt == 1){
                            field->matrix[i % field->n][ktmp] = j;
                            repeatcnt = 1;
                        }
                    } else if (i / field->n == 3){ //右の場合
                        for (int k = 0; k < placenum; k++){
                            subcnt = 0;
                            for (int l = 0; l < field->n; l++){
                                if (field->matrix[l][k] != j){
                                    subcnt++;
                                }
                                if (field->matrix[i % field->n][l] == j){
                                    cnt = 10000;
                                }
                            }
                            if (subcnt == field->n && field->matrix[i % field->n][k] == 0){
                                cnt++;
                                ktmp = k;
                            }
                        }
                        if (cnt == 1){
                            field->matrix[i % field->n][ktmp] = j;
                            repeatcnt = 1;
                        }
                    }
                    placenum--;
                }
            } 
        }
    } while (repeatcnt == 1);
}
