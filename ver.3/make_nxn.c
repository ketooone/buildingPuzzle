#include "flags.h"
#include "fields.h"
#include <stdio.h>
int count(field field);
void write_answer(field *field);
void method1(field *field, flag *flag);
void method2(field *field, flag *flag);
void method3(field *field, flag *flag);
void method4(field *field, flag *flag);
void method5(field *field, flag *flag);
void method6(field *field, flag *flag);

void make_nxn(int depth, field *field, flag *flag){
    method1(field, flag);
    method2(field, flag);
    method3(field, flag);
    //method5(field, flag);
    method6(field, flag);
    method5(field, flag);
    write_answer(field);
    if (count(*field)){
        printf("success!\n\n");
        field->completeCount++;
    } else {
        printf("false\n\n");
        field->falseCount++;
    }
}