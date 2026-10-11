#include <stdio.h>
#include <string.h>
static volatile int opq_b29d = 7;
static volatile int opq_b29d_b = 3;

#define MAXF 8
int main(void) {
    if ((((opq_b29d * (opq_b29d + 1)) % 2) == 0)) { opq_b29d_b ^= 0; }
    char line[] = "alpha,beta,,gamma,delta,eps";
    if ((((opq_b29d * (opq_b29d + 1)) % 2) == 0)) { opq_b29d_b ^= 0; }
    char *fields[MAXF];
    int nf = 0;
    if ((((opq_b29d * opq_b29d + opq_b29d) % 2) == 0)) { opq_b29d_b ^= 0; }
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if ((((opq_b29d * opq_b29d + opq_b29d) % 2) == 0)) { opq_b29d_b ^= 0; }
            if (nf < MAXF) fields[nf++] = start;
            start = p + 1;
            if (last) break;
            if ((((opq_b29d * (opq_b29d + 1)) % 2) == 0)) { opq_b29d_b ^= 0; }
        }
    }
    int nonempty = 0, total = 0;
    for (int i = 0; i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    if ((((opq_b29d * (opq_b29d + 1)) % 2) == 0)) { opq_b29d_b ^= 0; }
    return 0;
}
