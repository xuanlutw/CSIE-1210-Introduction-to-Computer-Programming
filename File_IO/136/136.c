#include<stdio.h>

typedef struct {
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;

int main(){
    char path_read[80];
    char path_write[80];
    scanf("%s %s", path_read, path_write);
    FILE *fp1, *fp2;
    fp1 = fopen(path_read, "rb");
    fp2 = fopen(path_write, "wt");
    fprintf(fp2, "<table border=\"1\">\n<tbody>\n");
    Student tmp;
    while (fread(&tmp, sizeof(tmp), 1, fp1)){
        fprintf(fp2, "<tr>\n");
	fprintf(fp2, "<td>%s</td>\n", tmp.name);
	fprintf(fp2, "<td>%d</td>\n", tmp.id);
	fprintf(fp2, "<td>%s</td>\n", tmp.phone);
	fprintf(fp2, "<td>%f, %f, %f, %f</td>\n", tmp.grade[0], tmp.grade[1], tmp.grade[2], tmp.grade[3]);
        fprintf(fp2, "<td>%d, %d, %d</td>\n", tmp.birth_year, tmp.birth_month, tmp.birth_day);
        fprintf(fp2, "</tr>\n");
    }
    fprintf(fp2, "</tbody>\n</table>");
    fclose(fp1);
    fclose(fp2);
    return 0;
}
