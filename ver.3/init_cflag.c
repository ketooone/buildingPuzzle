#include <stdlib.h>

int *init_cflag(int *cflag, int n){
    cflag = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        cflag[i] = 0;
    }
    return (cflag);
}