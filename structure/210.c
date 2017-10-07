#include<stdio.h>
#include<string.h>

struct my_data{
    char lastname[80];
    char firstname[80];
    char ID[80];
    int salary;
    int age;
} ;

typedef struct my_data Data; 

int to_int(char a[80]){
    int ans = 0;
    for (int i = 0;i < 80;++i){
        if (a[i] == '\0') break;
        ans = ans * 10 + a[i] - '0';
    }
    return ans;
}

void quick_scan(char *loc){
    int fl = 0, i = 0;
    char tmp;
    while (1){
        tmp = getchar();
        if ((tmp == ' ' || tmp == '\n') && fl) break;
        else if (tmp != ' ' && tmp != '\n'){
            loc[i] = tmp;
            ++i;
            fl = 1;
        }
    }
    loc[i] = '\0';
    return;
}
       
void quick_print(char *to_print){
    for (int i = 0;;++i){
        if (to_print[i] == '\0') break;
        putchar(to_print[i]);
    }
    return;
}
       
void print_data(Data *person, char print_list[10][80], int numlist){
    for (int i = 0;i < numlist;++i){
        if (!strcmp(print_list[i], "lastname")) quick_print(person->lastname);
        if (!strcmp(print_list[i], "firstname")) quick_print(person->firstname);
        if (!strcmp(print_list[i], "ID")) quick_print(person->ID);
        if (!strcmp(print_list[i], "salary")) printf("%d", person->salary);
        if (!strcmp(print_list[i], "age")) printf("%d", person->age);
        if (i == numlist - 1) printf("\n");
        else putchar(' ');
    }
    return;
}

void command(char t1[80], char t2[80], char t3[80], Data *person, int n, char print_list[10][80], int num_list){
    if (!strcmp(t1, "lastname") && !strcmp(t2, "==")){
        for (int i = 0;i < n;++i){
            if (!strcmp(t3, (person + i)->lastname)) print_data(person + i, print_list, num_list);
        }
    }
    if (!strcmp(t1, "lastname") && !strcmp(t2, "!=")){
        for (int i = 0;i < n;++i){
            if (strcmp(t3, (person + i)->lastname)) print_data(person + i, print_list, num_list);
        }
    }
    if (!strcmp(t1, "firstname") && !strcmp(t2, "==")){
        for (int i = 0;i < n;++i){
            if (!strcmp(t3, (person + i)->firstname)) print_data(person + i, print_list, num_list);
        }
    }
    if (!strcmp(t1, "firstname") && !strcmp(t2, "!=")){
        for (int i = 0;i < n;++i){
            if (strcmp(t3, (person + i)->firstname)) print_data(person + i, print_list, num_list);
        }
    }
    if (!strcmp(t1, "ID") && !strcmp(t2, "==")){
        for (int i = 0;i < n;++i){
            if (!strcmp(t3, (person + i)->ID)) print_data(person + i, print_list, num_list);
        }
    }
    if (!strcmp(t1, "ID") && !strcmp(t2, "!=")){
        for (int i = 0;i < n;++i){
            if (strcmp(t3, (person + i)->ID)) print_data(person + i, print_list, num_list);
        }
    }
    if (!strcmp(t1, "salary") && !strcmp(t2, "==")){
        for (int i = 0;i < n;++i){
            int k = to_int(t3);
            if (k == (person + i)->salary) print_data(person + i, print_list, num_list);
        }
    }
    if (!strcmp(t1, "salary") && !strcmp(t2, ">")){
        for (int i = 0;i < n;++i){
            int k = to_int(t3);
	    if (k < (person + i)->salary) print_data(person + i, print_list, num_list);
	}
    }
    if (!strcmp(t1, "salary") && !strcmp(t2, "<")){
        for (int i = 0;i < n;++i){
            int k = to_int(t3);
            if (k > (person + i)->salary) print_data(person + i, print_list, num_list);
        }
    }
    if (!strcmp(t1, "age") && !strcmp(t2, "==")){
        for (int i = 0;i < n;++i){
            int k = to_int(t3);
            if (k == (person + i)->age) print_data(person + i, print_list, num_list);
        }
    }
    if (!strcmp(t1, "age") && !strcmp(t2, ">")){
        for (int i = 0;i < n;++i){
            int k = to_int(t3);
            if (k < (person + i)->age) print_data(person + i, print_list, num_list);
        }
    }
    if (!strcmp(t1, "age") && !strcmp(t2, "<")){
        for (int i = 0;i < n;++i){
            int k = to_int(t3);
            if (k > (person + i)->age) print_data(person + i, print_list, num_list);
        }
    }
    return;
}
                 
int main(){
    int n;
    Data person[50];
    scanf("%d", &n);
    for (int i = 0;i < n;++i){
        scanf("%s", person[i].lastname);
        scanf("%s", person[i].firstname);
        scanf("%s", person[i].ID);
        scanf("%d", &person[i].salary);
        scanf("%d", &person[i].age);
    }
    int q;
    scanf("%d", &q);
    while (q--){
        char tmp[3][80];
        char print_list[10][80];
        int num_list = 0;
        quick_scan(tmp[0]);
        while (1){
            quick_scan(print_list[num_list]);
            if (!strcmp(print_list[num_list], "where")) break;
            ++num_list;
        }
        ++num_list;
        quick_scan(tmp[0]);
        quick_scan(tmp[1]);
        quick_scan(tmp[2]);
        command(tmp[0], tmp[1], tmp[2], person, n, print_list, num_list);
    }
    return 0;
}
