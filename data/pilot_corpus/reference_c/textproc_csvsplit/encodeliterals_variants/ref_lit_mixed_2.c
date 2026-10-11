#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = (0x1BF - 0x1BF);
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + (0xE33 - 0xE32);
            if (last) break;
        }
    }
    int nonempty = (0x29BC3AB2 ^ 0x29BC3AB2), total = (0xB36 - 0xB36);
    for (int i = (0x3FA8BB2F ^ 0x3FA8BB2F); i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return (0x1F2A2A87 ^ 0x1F2A2A87);
}
