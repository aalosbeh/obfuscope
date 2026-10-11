#include <stdio.h>
#include <string.h>
static volatile int opq_14a5 = 7;
static volatile int opq_14a5_b = 3;

#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    if ((((opq_14a5 * opq_14a5 + opq_14a5) % 2) == 0)) { opq_14a5_b ^= 0; }
    int nf = 0;
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            if ((((opq_14a5 * opq_14a5) % 4) == 2)) {
                { int jv_218af = opq_14a5 ^ 0xE5D;
                    jv_218af += (jv_218af >> 2) + 0x1F;
                    jv_218af = (jv_218af * 0x3E) % 0x7FFFFFFF;
                  (void)jv_218af; }
            }
            int last = (*p == '\0');
            if ((((opq_14a5 * opq_14a5 + opq_14a5_b * opq_14a5_b) % 4) == 3)) {
                { int jv_e3680 = opq_14a5 ^ 0x2756;
                    jv_e3680 = (jv_e3680 * 0x18) % 0x7FFFFFFF;
                    jv_e3680 += (jv_e3680 >> 2) + 0xFE;
                    jv_e3680 ^= (jv_e3680 << 3) | 0x65F0;
                  (void)jv_e3680; }
            }
            *p = '\0';
            if ((((opq_14a5 * opq_14a5 + opq_14a5_b * opq_14a5_b) % 4) == 3)) {
                { int jv_febb1 = opq_14a5 ^ 0xB9D2;
                    jv_febb1 += (jv_febb1 >> 2) + 0x1A;
                    jv_febb1 = (jv_febb1 * 0x3D) % 0x7FFFFFFF;
                    jv_febb1 ^= (jv_febb1 << 3) | 0xAAEF;
                  (void)jv_febb1; }
            }
            if (nf < MAXF) fields[nf++] = start;
            start = p + 1;
            if (last) break;
            if (((opq_14a5 * opq_14a5 - opq_14a5) % 2 == 0)) { opq_14a5_b ^= 0; }
        }
    }
    int nonempty = 0, total = 0;
    if ((((opq_14a5 * opq_14a5 + opq_14a5_b * opq_14a5_b) % 4) == 3)) {
        { int jv_2cb0a = opq_14a5 ^ 0x655A;
            jv_2cb0a = (jv_2cb0a * 0x14) % 0x7FFFFFFF;
            jv_2cb0a ^= (jv_2cb0a << 3) | 0x8A68;
          (void)jv_2cb0a; }
    }
    for (int i = 0; i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return 0;
}
