#include <stdio.h>
#include <string.h>
static volatile int opq_d1e5 = 7;
static volatile int opq_d1e5_b = 3;

#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    if ((((opq_d1e5 * opq_d1e5) % 4) == 2)) {
        { int jv_c7162 = opq_d1e5 ^ 0x280E;
            jv_c7162 ^= (jv_c7162 << 3) | 0x76EC;
            jv_c7162 += (jv_c7162 >> 2) + 0x8A;
            jv_c7162 = (jv_c7162 * 0x12) % 0x7FFFFFFF;
          (void)jv_c7162; }
    }
    char *fields[MAXF];
    if ((((opq_d1e5 * opq_d1e5) % 4) == 2)) {
        { int jv_43103 = opq_d1e5 ^ 0x885F;
            jv_43103 = (jv_43103 * 0x18) % 0x7FFFFFFF;
          (void)jv_43103; }
    }
    int nf = 0;
    if ((((opq_d1e5 * opq_d1e5 + opq_d1e5) % 2) == 0)) { opq_d1e5_b ^= 0; }
    char *start = line;
    if ((((opq_d1e5 * opq_d1e5 + opq_d1e5) % 2) == 0)) { opq_d1e5_b ^= 0; }
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + 1;
            if (last) break;
            if ((((opq_d1e5 * opq_d1e5) % 4) == 2)) {
                { int jv_67fa5 = opq_d1e5 ^ 0x103A;
                    jv_67fa5 = (jv_67fa5 * 0x18) % 0x7FFFFFFF;
                    jv_67fa5 ^= (jv_67fa5 << 3) | 0x1C4A;
                    jv_67fa5 += (jv_67fa5 >> 2) + 0x8;
                  (void)jv_67fa5; }
            }
        }
    }
    int nonempty = 0, total = 0;
    if ((((opq_d1e5 * opq_d1e5 + opq_d1e5) % 2) == 0)) { opq_d1e5_b ^= 0; }
    for (int i = 0; i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return 0;
}
