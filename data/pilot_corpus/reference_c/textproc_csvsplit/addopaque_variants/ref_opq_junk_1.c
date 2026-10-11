#include <stdio.h>
#include <string.h>
static volatile int opq_b96e = 7;
static volatile int opq_b96e_b = 3;

#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = 0;
    if ((((opq_b96e * opq_b96e) % 4) == 2)) {
        { int jv_a0bfa = opq_b96e ^ 0x5CF2;
            jv_a0bfa ^= (jv_a0bfa << 3) | 0x7F83;
          (void)jv_a0bfa; }
    }
    char *start = line;
    for (char *p = line; ; p++) {
        if ((((opq_b96e * opq_b96e + opq_b96e_b * opq_b96e_b) % 4) == 3)) {
            { int jv_37d49 = opq_b96e ^ 0xB58A;
                jv_37d49 = (jv_37d49 * 0x16) % 0x7FFFFFFF;
                jv_37d49 ^= (jv_37d49 << 3) | 0x3D0A;
                jv_37d49 += (jv_37d49 >> 2) + 0x97;
              (void)jv_37d49; }
        }
        if (*p == ',' || *p == '\0') {
            if ((((opq_b96e * opq_b96e + opq_b96e_b * opq_b96e_b) % 4) == 3)) {
                { int jv_9f9fa = opq_b96e ^ 0x86EA;
                    jv_9f9fa = (jv_9f9fa * 0x2A) % 0x7FFFFFFF;
                    jv_9f9fa += (jv_9f9fa >> 2) + 0xDF;
                  (void)jv_9f9fa; }
            }
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + 1;
            if ((((opq_b96e * opq_b96e + opq_b96e_b * opq_b96e_b) % 4) == 3)) {
                { int jv_ab171 = opq_b96e ^ 0xEFCF;
                    jv_ab171 = (jv_ab171 * 0x37) % 0x7FFFFFFF;
                    jv_ab171 += (jv_ab171 >> 2) + 0x85;
                  (void)jv_ab171; }
            }
            if (last) break;
            if ((((opq_b96e * opq_b96e + opq_b96e_b * opq_b96e_b) % 4) == 3)) {
                { int jv_e6694 = opq_b96e ^ 0xE315;
                    jv_e6694 ^= (jv_e6694 << 3) | 0xE592;
                    jv_e6694 = (jv_e6694 * 0x5) % 0x7FFFFFFF;
                  (void)jv_e6694; }
            }
        }
    }
    int nonempty = 0, total = 0;
    for (int i = 0; i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    if ((((opq_b96e * opq_b96e + opq_b96e_b * opq_b96e_b) % 4) == 3)) {
        { int jv_4d72b = opq_b96e ^ 0xF493;
            jv_4d72b += (jv_4d72b >> 2) + 0x29;
            jv_4d72b = (jv_4d72b * 0x34) % 0x7FFFFFFF;
            jv_4d72b ^= (jv_4d72b << 3) | 0x62C5;
          (void)jv_4d72b; }
    }
    return 0;
}
