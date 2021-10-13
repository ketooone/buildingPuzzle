#include "flags.h"
#include "fields.h"
#include <stdio.h>
int count(field field);
void write_answer(field *field);
void method1(field *field, flag *flag);
void method2(field *field, flag *flag);
void method3(field *field, flag *flag);
void method4(field *field, flag *flag);

void make_nxn(int depth, field *field, flag *flag){
    method1(field, flag);
    method2(field, flag);
    method3(field, flag);
    method4(field, flag);
    write_answer(field);
    if (count(*field)){
        printf("complete!\n\n");
    } else {
        printf("false\n\n");
    }
    /*
    if (depth == field->n * field->n && count(*field)){
        write_answer(field->matrix, field->n);
        flag->nflag = 1;
    }
    for (int k = 1; k <= field->n; k++){
        if ((flag->rflag[depth / field->n] >> (k - 1)) & 1){
			continue;
        } else if ((flag->cflag[depth % field->n] >> (k - 1)) & 1){
			continue;
        } else {
			field->matrix[depth / field->n][depth % field->n] = k;
            printf("matrix[%d][%d]=%d ", depth/field->n, depth % field->n, k);
			flag->rflag[depth / field->n] += (1 << (k - 1));
            printf("+=,rflag[%d]=%d ", depth / field->n, flag->rflag[depth / field->n]);
			flag->cflag[depth % field->n] += (1 << (k - 1));
            printf("+=,cflag[%d]=%d\n", depth % field->n, flag->cflag[depth % field->n]);
			make_nxn(depth + 1, field, flag);
			flag->rflag[depth / field->n] -= (1 << (k - 1));
            printf("-=,rflag[%d]=%d ", depth / field->n, flag->rflag[depth / field->n]);
			flag->cflag[depth % field->n] -= (1 << (k - 1));
            printf("-=,cflag[%d]=%d ", depth % field->n, flag->cflag[depth % field->n]);
		}
    }
    */
}