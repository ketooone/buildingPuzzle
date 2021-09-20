#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "flags.h"
#include "fields.h"

int **init_num(int **num, int n);
int **init_matrix(int **matrix, int n);
int *init_rflag(int *rflag, int n);
int *init_cflag(int *cflag, int n);
void make_nxn(int depth, field *field, flag *flag);
int check(int argc, char *argv[], int *nptr);
void all_free(flag flag, field field);

int main(int argc, char *argv[]){
    field field;
    flag flag;
    long cpu_time;
    double sec;

    if (argc == 2){
        field.n = argv[1][0] - '0';
        field.num = init_num(field.num, field.n);
        field.matrix = init_matrix(field.matrix, field.n);
        flag.rflag = init_rflag(flag.rflag, field.n);
        flag.cflag = init_cflag(flag.cflag, field.n);
        flag.nflag = 0;
        int cnt = 0;
        int num[field.n * field.n + 1];
        for (int i = 0; i < field.n * field.n + 1; i++){
            num[i] = 1;
        }
        while (1){
            for (int j = 0; j < field.n * field.n; j++){
                field.num[j / field.n][j % field.n] = num[j];
                //printf("%d ",field.num[j / field.n][j % field.n]);
            }
            //printf("\n");
            /*make_nxn(0, &field, &flag);
            if (flag.nflag == 0){
                printf("Error");
            }
            all_free(flag, field);*/
            int k = 0;
            while (k < field.n * field.n){
                if (k == 0){
                    num[0]++;
                }
                if (num[k] > field.n){
                    num[k + 1]++;
                    num[k] = 1;
                } else {
                    break;
                }
                k++;
                if (num[field.n * field.n] == 2){
                    cpu_time = clock();
                    sec = (double)cpu_time / CLOCKS_PER_SEC;
                    printf("%f秒\n",sec);
                    return (0);
                }
            }
        }
    } else {
        printf("Error");
    }
    return (0);
}