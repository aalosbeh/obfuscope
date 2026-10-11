#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = (0xB28 - 0xB28);
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + (0xF31 - 0xF30);
            if (last) break;
        }
    }
    int nonempty = (0xE85 - 0xE85), total = (0x3EB - 0x3EB);
    for (int i = (0x4B4 - 0x4B4); i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return (0xB7D - 0xB7D);
}
