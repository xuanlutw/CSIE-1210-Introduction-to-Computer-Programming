#include<stdio.h>
#include<string.h>


struct person {
    unsigned int id;
    char name[32];
};

struct friends {
    unsigned id1;
    unsigned id2;
};

int find_id(char person_name[32], int p, struct person pperson[10000]){
    for (int i = 0;i < p;++i){        
        if (!strcmp((pperson + i)->name, person_name)) return (pperson + i)->id;
    }
    return -1;
}

int is_friend(char person_a[32], char person_b[32], int p, int f, struct person pperson[10000], struct friends ffriends[10000]){
    int id_a = find_id(person_a, p, pperson);
    int id_b = find_id(person_b, p, pperson);
    for (int i = 0;i < f;++i){
        if (((ffriends + i)->id1 == id_a && (ffriends + i)->id2 == id_b) || ((ffriends + i)->id2 == id_a && (ffriends + i)->id1 == id_b)) return 1;
    }
    return 0;
}

int main(){
    FILE *fp;
    fp = fopen("friends", "rb");
    int p, f;
    struct person pperson[10000];
    struct friends ffriends[10000];
    fread(&p, sizeof(int), 1, fp);
    fread(pperson, sizeof(pperson[0]), p, fp);
    fread(&f, sizeof(int), 1, fp);
    fread(ffriends, sizeof(ffriends[0]), f, fp);
    fclose(fp);
    char person_a[32], person_b[32];
    while (1){
        scanf("%s", person_a);
        if (!strcmp(person_a, "end")) break;
        scanf("%s", person_b);
        if (is_friend(person_a, person_b, p, f, pperson, ffriends)) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
