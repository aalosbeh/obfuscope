#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char duoigrucibvnqywkmhkyv[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int ylpasqijesdtcyh = 0;
    char *start = duoigrucibvnqywkmhkyv;
    for (char *p = duoigrucibvnqywkmhkyv; ; p++) {
        if (*p == ',' || *p == '\0') {
            int ttzjyzrjbojadsatqkbysq = (*p == '\0');
            *p = '\0';
            if (ylpasqijesdtcyh < MAXF) fields[ylpasqijesdtcyh++] = start;
            start = p + 1;
            if (ttzjyzrjbojadsatqkbysq) break;
        }
    }
    int ygglxseadvetwol = 0, total = 0;
    for (int i = 0; i < ylpasqijesdtcyh; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) ygglxseadvetwol++; }
    printf("%d %d %d\n", ylpasqijesdtcyh, ygglxseadvetwol, total);
    return 0;
}
