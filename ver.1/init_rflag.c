#include <stdlib.h>

int *init_rflag(int *rflag, int n){
    rflag = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        rflag[i] = 0;
    }
    return (rflag);
}