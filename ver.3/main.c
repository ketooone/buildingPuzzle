#include <stdio.h>
#include <stdlib.h>
#include "flags.h"
#include "fields.h"
#define N 4

int **init_num(int **num, int n);
int **init_matrix(int **matrix, int n);
int *init_rflag(int *rflag, int n);
int *init_cflag(int *cflag, int n);
void make_nxn(int depth, field *field, flag *flag);
int check(int argc, char *argv[], int *nptr);
void all_free(flag flag, field field);

int main(){
    field field;
    flag flag;
    FILE *fp;
    int data[100][N * 4];

    fp = fopen("num.dat", "r");
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < N * 4; j++){
            fscanf(fp, "%d", &data[i][j]);
        }
    }
    fclose(fp);

    for (int i = 0; i < 20; i++){
        printf("No.%d\n", i + 1);
        field.n = N;
        field.num = init_num(field.num, field.n);
        field.matrix = init_matrix(field.matrix, field.n);
        flag.rflag = init_rflag(flag.rflag, field.n);
        flag.cflag = init_cflag(flag.cflag, field.n);
        flag.nflag = 0;
        for (int j = 0; j < field.n * field.n; j++){
            field.num[j / field.n][j % field.n] = data[i][j];
        }
        make_nxn(0, &field, &flag);
        all_free(flag, field);
    }
    return (0);
}