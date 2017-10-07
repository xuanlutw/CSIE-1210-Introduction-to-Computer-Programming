#include<stdio.h>
#include<string.h>

struct employee {
  int id;
  char first_name[32];
  char last_name[32];
  int boss_id;
};

typedef struct employee slavery;

int super_boss(int i, int find_boss, slavery com[32]){
    int pre = com[i].boss_id;
    int nxt = i;
    while(1){
        if (pre == find_boss){
            pre = -1;
            break;
        }
        if (pre == nxt) break;
        nxt = pre;
        pre = com[nxt].boss_id;
    }
    return pre;
}

int main(){
    int n, id_cmp[32];
    slavery com[32];
    scanf("%d", &n);
    for (int i = 0;i < n;++i){
        scanf("%d", &com[i].id);
        scanf("%s", com[i].first_name);
        scanf("%s", com[i].last_name);
        scanf("%d", &com[i].boss_id);
        id_cmp[i] = com[i].id;
        com[i].id = i;
    }
    for (int i = 0;i < n;++i){
        for (int j = 0;j < n;++j){
            if (com[i].boss_id == id_cmp[j]){
                com[i].boss_id = j;
                break;
            }
        }
    }
    int q;
    scanf("%d", &q);
    while(q--){
        int id_a, id_b;
        char tmpfa[32], tmpla[32], tmpfb[32], tmplb[32];
        scanf ("%s%s%s%s", tmpfa, tmpla, tmpfb, tmplb);
        for (int i = 0;i < n;++i){
            if (!strcmp(tmpfa, com[i].first_name) && !strcmp(tmpla, com[i].last_name)) id_a = i;
            if (!strcmp(tmpfb, com[i].first_name) && !strcmp(tmplb, com[i].last_name)) id_b = i;
        }
        int sbs_a = super_boss(id_a, id_b, com);
        int sbs_b = super_boss(id_b, id_a, com);
        if (sbs_a == -1) printf("subordinate\n");
        else if (sbs_b == -1) printf("supervisor\n");
        else if (sbs_a == sbs_b) printf("colleague\n");
        else printf("unrelated\n"); 
    }
    return 0;
}
