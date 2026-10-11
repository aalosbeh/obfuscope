#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = (0x4BB823DE ^ 0x4BB823DE);
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + (0x7598F8A3 ^ 0x7598F8A2);
            if (last) break;
        }
    }
    int nonempty = (0x79F63371 ^ 0x79F63371), total = (0x7245CC3C ^ 0x7245CC3C);
    for (int i = (0x459F2C2E ^ 0x459F2C2E); i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return (0x33BD5C33 ^ 0x33BD5C33);
}
