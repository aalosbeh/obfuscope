#include <stdio.h>
#include <string.h>
static volatile int opq_61cd = 7;
static volatile int opq_61cd_b = 3;

#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    if ((((opq_61cd * opq_61cd + opq_61cd) % 2) == 0)) { opq_61cd_b ^= 0; }
    char *fields[MAXF];
    int nf = 0;
    char *start = line;
    if (((opq_61cd * opq_61cd - opq_61cd) % 2 == 0)) { opq_61cd_b ^= 0; }
    for (char *p = line; ; p++) {
        if (((opq_61cd * opq_61cd - opq_61cd) % 2 == 0)) { opq_61cd_b ^= 0; }
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            if (((opq_61cd * opq_61cd - opq_61cd) % 2 == 0)) { opq_61cd_b ^= 0; }
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            if ((((opq_61cd * (opq_61cd + 1)) % 2) == 0)) { opq_61cd_b ^= 0; }
            start = p + 1;
            if ((((opq_61cd * opq_61cd + opq_61cd) % 2) == 0)) { opq_61cd_b ^= 0; }
            if (last) break;
        }
    }
    int nonempty = 0, total = 0;
    for (int i = 0; i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return 0;
}
