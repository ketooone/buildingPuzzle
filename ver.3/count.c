#include "fields.h"

int count_colup(int cu, int n, int **matrix){
    int cnt;
    int pre;

    cnt = 0;
    pre = 0;
    for (int i = 0; i < n; i++){
        if (pre < matrix[i][cu]){
            pre = matrix[i][cu];
            cnt++;
        }
    }
    return (cnt);
}

int count_coldown(int cd, int n, int **matrix){
    int cnt;
    int pre;

    cnt = 0;
    pre = 0;
    for (int i = n - 1; i >= 0; i--){
        if (pre < matrix[i][cd]){
            pre = matrix[i][cd];
            cnt++;
        }
    }
    return (cnt);
}

int count_rowleft(int rl, int n, int **matrix){
    int cnt;
    int pre;

    cnt = 0;
    pre = 0;
    for (int j = 0; j < n; j++){
        if (pre < matrix[rl][j]){
            pre = matrix[rl][j];
            cnt++;
        }
    }
    return (cnt);
}

int count_rowright(int rr, int n, int **matrix){
    int cnt;
    int pre;

    cnt = 0;
    pre = 0;
    for (int j = n - 1; j >= 0; j--){
        if (pre < matrix[rr][j]){
            pre = matrix[rr][j];
            cnt++;
        }
    }
    return (cnt);
}

int count(field field){
    for (int i = 0; i < field.n; i++){
        if (count_colup(i, field.n, field.matrix) != field.num[0][i]){
            return (0);
        }
        if (count_coldown(i, field.n, field.matrix) != field.num[1][i]){
            return (0);
        }
        if (count_rowleft(i, field.n, field.matrix) != field.num[2][i]){
            return (0);
        }
        if (count_rowright(i, field.n, field.matrix) != field.num[3][i]){
            return (0);
        }
    }
    return (1);
}