int check_num(char *argv[], int *nptr){
    int i;

    i = 0;
    while (argv[1][i] != '\0'){
        if (i % 2 == 1 && argv[1][i] != ' '){
            return (0);
        }
        if (i % 2 == 0 && !('1' <= argv[1][i] && argv[1][i] <= *nptr + '0')){
            return (0);
        }
        i++;
    }
    return (1);
}

int check_len(char *argv[]){
    int i;
    int len;

    i = 0;
    len = 4;
    while (argv[1][i] != '\0'){
        i++;
    }    
    for (int len = 4; len <= 9; len++){
        if (i == len * 4 * 2 - 1){
            return (len);
        }
    }
    return (0);
}

int check_argc(int argc){
    if (argc == 2){
        return (1);
    } else {
        return (0);
    }
}

int check(int argc, char *argv[], int *nptr){
    if (check_argc(argc) == 0){
        return (0);
    }
    *nptr = check_len(argv);
    if (*nptr == 0){
        return (0);
    }
    if (check_num(argv, nptr) == 0){
        return (0);
    }
    return (1);
}