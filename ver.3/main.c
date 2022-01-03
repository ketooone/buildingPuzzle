#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "flags.h"
#include "fields.h"
#define N 4

int **init_num(int **num, int n);
int **init_matrix(int **matrix, int n);
int *init_rflag(int *rflag, int n);
void make_nxn(int depth, field *field, flag *flag);
int check(int argc, char *argv[], int *nptr);
void all_free(flag flag, field field);

int main(){
    field field;
    flag flag;
    FILE *fp;
    int data[102][N * 4];
    field.completeCount = 0;
    field.falseCount = 0;
    field.falseBilCount = 0;
    field.totalCount = 0;
    field.zeroCount = 0;
    int cnt = 0;
    // double time = 0;
    // clock_t start_clock;
    // clock_t end_clock;


    fp = fopen("num.dat", "r");
    for (int i = 0; i < 102; i++){
        for (int j = 0; j < N * 4; j++){
            fscanf(fp, "%d", &data[i][j]);
        }
    }
    fclose(fp);

    // start_clock = clock();
    for (int i = 0; i < 100; i++){
        printf("No.%d\n", i + 1);
        field.n = N;
        field.num = init_num(field.num, field.n);
        field.matrix = init_matrix(field.matrix, field.n);
        flag.rflag = init_rflag(flag.rflag, field.n);
        flag.nflag = 0;
        for (int j = 0; j < field.n * field.n; j++){
            field.num[j / field.n][j % field.n] = data[i][j];
        }
        
        make_nxn(0, &field, &flag);
        all_free(flag, field);
    }
    // end_clock = clock();
    printf("success:%d\n", field.completeCount);
    printf("false:%d\n", field.falseCount);
    printf("falseCount-zeroCount:%d\n", field.falseCount - field.zeroCount); //失敗問題数のうちビルが埋まってる問題数
    printf("zeroCount:%d\n", field.zeroCount); //失敗問題数のうちビルが埋まっていない問題数
    printf("totalCount:%d\n", field.totalCount); //埋まっているビルの総数
    printf("falseBilCount:%d\n", field.falseBilCount); //失敗問題のうち埋まっているビルの総数
    printf("totalCount_ave:%f\n", (double)field.totalCount / 100); //埋まっているビルの平均
    printf("falseBilCount_ave:%f\n", (double)field.falseBilCount / field.falseCount); //失敗問題のうち埋まっているビルの平均
    printf("falseBilCount_ave_notzero:%f\n", (double)field.falseBilCount / (field.falseCount - field.zeroCount)); //失敗問題のうちビルが埋まっている問題のビルの平均

    // printf("埋まったビルの数:%d\n",cnt);
    // printf("time:%f\n",time);
    // printf("time:%f\n",(double)(end_clock - start_clock) / CLOCKS_PER_SEC);
    // printf("time:%f\n",(double)(end_clock - start_clock));
    return (0);
}