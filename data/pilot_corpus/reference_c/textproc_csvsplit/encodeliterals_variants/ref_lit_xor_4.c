#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = (0x26A55C33 ^ 0x26A55C33);
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + (0x5E51BE16 ^ 0x5E51BE17);
            if (last) break;
        }
    }
    int nonempty = (0x57B92503 ^ 0x57B92503), total = (0x44A3AFCD ^ 0x44A3AFCD);
    for (int i = (0x65D00497 ^ 0x65D00497); i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return (0x311C63FC ^ 0x311C63FC);
}
