#include<stdio.h>

int main(){
    int n, m;
    int arr[500];
    int task[500];
    int done[500] = {0};
    int proc[2][500][500];
    int mac[500];
    scanf("%d%d", &n, &m);
    for (int i = 0;i < m;++i){
        scanf("%d%d", &arr[i], &task[i]);
        for (int j = 0;j < task[i];++j) scanf("%d%d", &proc[0][i][j], &proc[1][i][j]);
    }
    while (1){
        int fl = 1;
        for (int i = 0;i < m;++i){
            if(done[i] != task[i]) fl = 0;
        }
        if(fl) break;
        int mintime = 1500000, num;
        for (int i = 0;i < m;++i){
            if (done[i] == task[i]) continue;
            int star = (mac[proc[0][i][done[i]]] > arr[i]?mac[proc[0][i][done[i]]]:arr[i]);
            if (star + proc[1][i][done[i]] < mintime){
                mintime = star + proc[1][i][done[i]];
                num = i;
            }
        }
        mac[proc[0][num][done[num]]] = mintime;
        arr[num] = mintime;
        ++done[num];
    }
    for (int i = 0;i < m;++i) printf("%d\n", arr[i]);
    return 0;
}
