#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = (0x8AD - 0x8AD);
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + (0xB68 - 0xB67);
            if (last) break;
        }
    }
    int nonempty = (0x30872449 ^ 0x30872449), total = (0x1BD - 0x1BD);
    for (int i = (0x12BB6313 ^ 0x12BB6313); i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return (0x980 - 0x980);
}
