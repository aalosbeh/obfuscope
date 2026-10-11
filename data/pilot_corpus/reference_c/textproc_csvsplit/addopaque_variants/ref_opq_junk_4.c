#include <stdio.h>
#include <string.h>
static volatile int opq_de29 = 7;
static volatile int opq_de29_b = 3;

#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    if ((((opq_de29 * opq_de29 + opq_de29_b * opq_de29_b) % 4) == 3)) {
        { int jv_ded96 = opq_de29 ^ 0x3998;
            jv_ded96 = (jv_ded96 * 0xA) % 0x7FFFFFFF;
          (void)jv_ded96; }
    }
    char *fields[MAXF];
    int nf = 0;
    char *start = line;
    if ((((opq_de29 * opq_de29 + opq_de29_b * opq_de29_b) % 4) == 3)) {
        { int jv_eda36 = opq_de29 ^ 0xE7CF;
            jv_eda36 = (jv_eda36 * 0x21) % 0x7FFFFFFF;
            jv_eda36 += (jv_eda36 >> 2) + 0xD5;
          (void)jv_eda36; }
    }
    for (char *p = line; ; p++) {
        if ((((opq_de29 * opq_de29) % 4) == 2)) {
            { int jv_2ffe2 = opq_de29 ^ 0x69E;
                jv_2ffe2 ^= (jv_2ffe2 << 3) | 0x6341;
                jv_2ffe2 += (jv_2ffe2 >> 2) + 0xCD;
                jv_2ffe2 = (jv_2ffe2 * 0x34) % 0x7FFFFFFF;
              (void)jv_2ffe2; }
        }
        if (*p == ',' || *p == '\0') {
            if ((((opq_de29 * opq_de29) % 4) == 2)) {
                { int jv_7075c = opq_de29 ^ 0xE7C9;
                    jv_7075c ^= (jv_7075c << 3) | 0xA01B;
                    jv_7075c += (jv_7075c >> 2) + 0x5C;
                  (void)jv_7075c; }
            }
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            if ((((opq_de29 * opq_de29 + opq_de29_b * opq_de29_b) % 4) == 3)) {
                { int jv_c926c = opq_de29 ^ 0x9286;
                    jv_c926c ^= (jv_c926c << 3) | 0xA889;
                    jv_c926c = (jv_c926c * 0x28) % 0x7FFFFFFF;
                  (void)jv_c926c; }
            }
            start = p + 1;
            if (last) break;
        }
    }
    int nonempty = 0, total = 0;
    for (int i = 0; i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    if ((((opq_de29 * opq_de29) % 4) == 2)) {
        { int jv_2f809 = opq_de29 ^ 0x3DEB;
            jv_2f809 = (jv_2f809 * 0x22) % 0x7FFFFFFF;
            jv_2f809 += (jv_2f809 >> 2) + 0x15;
          (void)jv_2f809; }
    }
    return 0;
}
