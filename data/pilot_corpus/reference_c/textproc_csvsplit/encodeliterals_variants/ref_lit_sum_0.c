#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = (0x888 - 0x888);
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + (0x9AD - 0x9AC);
            if (last) break;
        }
    }
    int nonempty = (0x8A6 - 0x8A6), total = (0x9F7 - 0x9F7);
    for (int i = (0x9FF - 0x9FF); i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return (0xF07 - 0xF07);
}
