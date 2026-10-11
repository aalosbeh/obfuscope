#include <stdio.h>
#include <string.h>
static volatile int opq_42da = 7;
static volatile int opq_42da_b = 3;

#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = 0;
    if ((((opq_42da * (opq_42da + 1)) % 2) == 0)) { opq_42da_b ^= 0; }
    char *start = line;
    if ((((opq_42da * (opq_42da + 1)) % 2) == 0)) { opq_42da_b ^= 0; }
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            if (((opq_42da * opq_42da - opq_42da) % 2 == 0)) { opq_42da_b ^= 0; }
            start = p + 1;
            if ((((opq_42da * (opq_42da + 1)) % 2) == 0)) { opq_42da_b ^= 0; }
            if (last) break;
            if (((opq_42da * opq_42da - opq_42da) % 2 == 0)) { opq_42da_b ^= 0; }
        }
    }
    int nonempty = 0, total = 0;
    if (((opq_42da * opq_42da - opq_42da) % 2 == 0)) { opq_42da_b ^= 0; }
    for (int i = 0; i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return 0;
}
