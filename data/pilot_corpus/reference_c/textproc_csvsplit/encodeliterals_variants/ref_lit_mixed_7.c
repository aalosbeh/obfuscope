#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = (0x6945EE01 ^ 0x6945EE01);
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + (0xE36 - 0xE35);
            if (last) break;
        }
    }
    int nonempty = (0x366 - 0x366), total = (0x7C - 0x7C);
    for (int i = (0x6E6E4D5E ^ 0x6E6E4D5E); i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return (0x7081C3B7 ^ 0x7081C3B7);
}
