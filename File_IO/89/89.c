#include<stdio.h>

int main(){
    int key;
    scanf("%d", &key);
    FILE *fp1, *fp2;
    fp1 = fopen("test", "rb");
    fp2 = fopen("test.enc", "wb");
    char tmp;
    while (fread(&tmp, sizeof(char), 1, fp1)){
        tmp ^= key;
        fwrite(&tmp, sizeof(char), 1, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
