#include "flags.h"
#include "fields.h"
#include <stdio.h>
int count(field field);
void write_answer(int **matrix, int n);

void make_nxn(int depth, field *field, flag *flag){
    if (depth == field->n * field->n /*&& count(*field)*/){
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
}