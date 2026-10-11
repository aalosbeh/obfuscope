#include <stdio.h>
#include <string.h>
static volatile int opq_8b18 = 7;
static volatile int opq_8b18_b = 3;

#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    if ((((opq_8b18 * opq_8b18 + opq_8b18) % 2) == 0)) { opq_8b18_b ^= 0; }
    char *fields[MAXF];
    if (((opq_8b18 * opq_8b18 - opq_8b18) % 2 == 0)) { opq_8b18_b ^= 0; }
    int nf = 0;
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            if ((((opq_8b18 * (opq_8b18 + 1)) % 2) == 0)) { opq_8b18_b ^= 0; }
            int last = (*p == '\0');
            if (((opq_8b18 * opq_8b18 - opq_8b18) % 2 == 0)) { opq_8b18_b ^= 0; }
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + 1;
            if ((((opq_8b18 * (opq_8b18 + 1)) % 2) == 0)) { opq_8b18_b ^= 0; }
            if (last) break;
        }
    }
    int nonempty = 0, total = 0;
    if ((((opq_8b18 * (opq_8b18 + 1)) % 2) == 0)) { opq_8b18_b ^= 0; }
    for (int i = 0; i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return 0;
}
