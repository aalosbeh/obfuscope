#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = (0x3B0BE6D5 ^ 0x3B0BE6D5);
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + (0x6722E80C ^ 0x6722E80D);
            if (last) break;
        }
    }
    int nonempty = (0x27998703 ^ 0x27998703), total = (0x7755BDF3 ^ 0x7755BDF3);
    for (int i = (0x5BD804C2 ^ 0x5BD804C2); i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return (0x19CA06EC ^ 0x19CA06EC);
}
