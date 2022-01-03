#include <stdlib.h>

int *init_rflag(int *rflag, int n){
    rflag = (int *)malloc(sizeof(int) * (n * n));
    for (int i = 0; i < n * n; i++){
        rflag[i] = 0;
    }
    return (rflag);
}