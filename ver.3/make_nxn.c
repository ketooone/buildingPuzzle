#include "flags.h"
#include "fields.h"
#include <stdio.h>
#include <time.h>

int count(field field);
void write_answer(field *field);
void method1(field *field, flag *flag);
void method2(field *field, flag *flag);
void method3(field *field, flag *flag);
void method4(field *field, flag *flag);
void method5(field *field, flag *flag);
void method6(field *field, flag *flag);
void method7(field *field, flag *flag);
void method8(field *field, flag *flag);

void make_nxn(int depth, field *field, flag *flag){
    // clock_t start_clock;
    // clock_t end_clock;
    int cnt = 0;
    // struct timespec start,end;

    // start_clock = clock();
    // timespec_get(&start, TIME_UTC);
    method1(field, flag);
    method2(field, flag);
    method3(field, flag);
    method4(field, flag);
    method8(field, flag);
    // method6(field, flag);
    // method5(field, flag);
    // method5(field, flag);
    // method7(field, flag);
    // method5(field, flag);
    // method7(field, flag);
    // method5(field, flag);
    // method6(field, flag);
    // method5(field, flag);
    // method3(field, flag);
    // method5(field, flag);
    // end_clock = clock();
    // timespec_get(&end, TIME_UTC);
    // long diff = end.tv_nsec - start.tv_nsec;
    write_answer(field);
    if (count(*field)){
        for (int i = 0; i < field->n; i++){
            for (int j = 0; j < field->n; j++){
                if (field->matrix[i][j] != 0){
                    cnt++;
                }
            }
        }
        printf("success!\n");
        field->completeCount++;
        field->totalCount += cnt;
    } else {
        for (int i = 0; i < field->n; i++){
            for (int j = 0; j < field->n; j++){
                if (field->matrix[i][j] != 0){
                    cnt++;
                }
            }
        }
        printf("false\n");
        field->falseCount++;
        field->totalCount += cnt;
        field->falseBilCount += cnt;
        if (cnt == 0){
            field->zeroCount++;
        }
    }
    printf("building:%d\n\n", cnt);
    // printf("time:%f\n",(double)(end_clock - start_clock));
    // printf("処理時間は%loナノ秒です",diff);
    // return ((double)(end_clock - start_clock) / CLOCKS_PER_SEC);
    // return (cnt);
}