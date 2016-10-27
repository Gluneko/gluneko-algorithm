// 可以计算出time = 3600*h + 60*m + s比较，也可以直接字符串比较，注意string对象不能直接使用scanf
#include<stdio.h>
#include<string.h>

char firstPer[20];
char lastPer[20];
char firstTime[20] = "23:59:59";
char lastTime[20] = "00:00:00";

int main() {
    int n;
    scanf("%d", &n);
    char id[20], in[20], out[20];
    while (n--) {
        scanf("%s%s%s", id, in, out);
        if (strcmp(in, firstTime) < 0) {
            strcpy(firstPer, id);
            strcpy(firstTime, in);
        }
        if (strcmp(out, lastTime) > 0) {
            strcpy(lastPer, id);
            strcpy(lastTime, out);
        }

    }
    printf("%s %s\n", firstPer, lastPer);

    return 0;
}