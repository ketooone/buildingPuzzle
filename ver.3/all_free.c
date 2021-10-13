#include <stdlib.h>
#include "flags.h"
#include "fields.h"

void all_free(flag flag, field field){
    for (int i = 0; i < field.n; i++){
        free(field.num[i]);
        free(field.matrix[i]);
    }
    free(field.num);
    free(field.matrix);
}