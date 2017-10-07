#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int num;
    char name[128][128];
    int value[128];
}Variable;

void init_variable(Variable *variable){
    variable->num = 0;
    char tmp[128];
    while (1){
        scanf("%s", tmp);
        if (!strcmp(tmp, "END")) break;
        strcpy(variable->name[variable->num], tmp);
        scanf("%*s%d", &variable->value[variable->num]);
        ++variable->num;
    }
    scanf("%*c"); //\n
    return;
}

int read_variable(const Variable *variable, char name[128]){
    for (int i = 0;i < variable->num;++i){
        if (!strcmp(variable->name[i], name)) return variable->value[i];
    }
    return -1;
}

void write_variable(Variable *variable, char name[128], int value){
    for (int i = 0;i < variable->num;++i){
        if (!strcmp(variable->name[i], name)){
            variable->value[i] = value;
            return;
        }
    }
    return;
}

int main(){
    Variable variable;
    init_variable(&variable);
    char statements[1024][256] = {0};
    for (int i = 1;;++i){
        char *pc;
        pc = fgets(statements[i], 256, stdin);
        if (!pc) break;
        statements[i][strlen(statements[i]) - 1] = '\0';
    }
#ifdef DEBUG
    printf("num = %d\n", variable.num);
    for (int i = 0;i < variable.num;++i) printf("%s = %d\n", variable.name[i], variable.value[i]);
    printf("===========================\n");
    for (int i = 1;strcmp(statements[i], "");++i) printf("%s~\n", statements[i]);
#endif
    int counter = 1;
    while (1){
#ifdef DEBUG
        printf("%d\n", counter);
#endif
        char tmp[256];
        strcpy(tmp, statements[counter]);
        int index;
        for (index = 0;tmp[index] != ' ' && tmp[index] != '\0';++index);
        tmp[index] = '\0';
        if (!strcmp(tmp, "STOP")){
            break;
        }
        else if (!strcmp(tmp, "GOTO")){
            counter = atoi(tmp + 5);
        }
        else if (!strcmp(tmp, "PRINT")){
            printf("%d\n", read_variable(&variable, (tmp + 6)));
            ++counter;
        }
        else if (!strcmp(tmp, "IF")){
            int index2, index3;
            for (index = 3;tmp[index] != ' ';++index);
            tmp[index] = '\0';
            for (index2 = index + 1;tmp[index2] != ' ';++index2);
            tmp[index2] = '\0';
            for (index3 = index2 + 1;tmp[index3] != ' ';++index3);
            tmp[index3] = '\0';
            int val1 = read_variable(&variable, tmp + 3);
            int val2 = read_variable(&variable, tmp + index2 + 1);
            if (!strcmp(tmp + index + 1, "==") && val1 == val2) counter = atoi(tmp + index3 + 6); 
            else if (!strcmp(tmp + index + 1, "!=") && val1 != val2) counter = atoi(tmp + index3 + 6); 
            else if (!strcmp(tmp + index + 1, ">") && val1 > val2) counter = atoi(tmp + index3 + 6); 
            else if (!strcmp(tmp + index + 1, "<") && val1 < val2) counter = atoi(tmp + index3 + 6); 
            else if (!strcmp(tmp + index + 1, ">=") && val1 >= val2) counter = atoi(tmp + index3 + 6); 
            else if (!strcmp(tmp + index + 1, "<=") && val1 <= val2) counter = atoi(tmp + index3 + 6); 
            else ++counter;
        }
        else{
            int index2;
            for (index2 = index + 3;tmp[index2] != ' ';++index2);
            tmp[index2] = '\0';
            int val1 = read_variable(&variable, tmp + index + 3);
            int val2 = read_variable(&variable, tmp + index2 + 3); 
            if (*(tmp + index2 + 1) == '+') write_variable(&variable, tmp, val1 + val2);
            if (*(tmp + index2 + 1) == '-') write_variable(&variable, tmp, val1 - val2);
            if (*(tmp + index2 + 1) == '*') write_variable(&variable, tmp, val1 * val2);
            if (*(tmp + index2 + 1) == '/') write_variable(&variable, tmp, val1 / val2);
            if (*(tmp + index2 + 1) == '%') write_variable(&variable, tmp, val1 % val2);
            ++counter;
        }
    }
    return 0;
}
