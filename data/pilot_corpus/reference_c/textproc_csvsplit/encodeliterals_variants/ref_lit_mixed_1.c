#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = (0x91D - 0x91D);
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + (0xC59 - 0xC58);
            if (last) break;
        }
    }
    int nonempty = (0xA56 - 0xA56), total = (0x38963458 ^ 0x38963458);
    for (int i = (0x2E9 - 0x2E9); i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return (0x7FAD817D ^ 0x7FAD817D);
}
