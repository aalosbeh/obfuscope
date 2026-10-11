#include <stdio.h>
#include <string.h>
static volatile int opq_8c56 = 7;
static volatile int opq_8c56_b = 3;

#define MAXF 8
int main(void) {
    if ((((opq_8c56 * opq_8c56 + opq_8c56) % 2) == 0)) { opq_8c56_b ^= 0; }
    char line[] = "alpha,beta,,gamma,delta,eps";
    if ((((opq_8c56 * opq_8c56 + opq_8c56_b * opq_8c56_b) % 4) == 3)) {
        { int jv_ff512 = opq_8c56 ^ 0xB4B1;
            jv_ff512 ^= (jv_ff512 << 3) | 0x61B3;
            jv_ff512 += (jv_ff512 >> 2) + 0x40;
          (void)jv_ff512; }
    }
    char *fields[MAXF];
    if (((opq_8c56 * opq_8c56 - opq_8c56) % 2 == 0)) { opq_8c56_b ^= 0; }
    int nf = 0;
    char *start = line;
    if ((((opq_8c56 * opq_8c56) % 4) == 2)) {
        { int jv_831e4 = opq_8c56 ^ 0x2EAF;
            jv_831e4 += (jv_831e4 >> 2) + 0xF5;
          (void)jv_831e4; }
    }
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            if (((opq_8c56 * opq_8c56 - opq_8c56) % 2 == 0)) { opq_8c56_b ^= 0; }
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + 1;
            if ((((opq_8c56 * opq_8c56 + opq_8c56_b * opq_8c56_b) % 4) == 3)) {
                { int jv_5c1ba = opq_8c56 ^ 0xAB26;
                    jv_5c1ba ^= (jv_5c1ba << 3) | 0x25D;
                  (void)jv_5c1ba; }
            }
            if (last) break;
        }
    }
    int nonempty = 0, total = 0;
    for (int i = 0; i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return 0;
}
