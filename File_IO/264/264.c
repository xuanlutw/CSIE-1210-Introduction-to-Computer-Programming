#include<stdio.h>

int main(){
    char path[256];
    scanf("%s", path);
    FILE *fp;
    fp = fopen(path, "rb");
    int n;
    short ans[2][1<<15] = {0};
    fread(&n, sizeof(int), 1, fp);
    while (n--){
        short tmp;
        fread(&tmp, sizeof(short), 1, fp);
        if (tmp >= 0) ++ans[0][tmp];
        else ++ans[1][-(tmp + 1)];
    }
    int max = 0, num = -(1 << 20);
    for (int i = 0;i < (1<<15);++i){
        if (ans[0][i] >= max){
            max = ans[0][i]; 
            num = i;
        }
        if ((ans[1][i] == max && (-i - 1) > num) || (ans[1][i] > max)){
            max = ans[1][i]; 
            num = -i - 1;
        }
    }
    printf("%d\n%d", num, max);
}
        
