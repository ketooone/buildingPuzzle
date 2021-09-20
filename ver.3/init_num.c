#include <stdlib.h>

int **init_num(int **num, int n){
    num = (int **)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++){
        num[i] = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++){
            num[i][j] = 0;
        }
    }
    return (num);
}