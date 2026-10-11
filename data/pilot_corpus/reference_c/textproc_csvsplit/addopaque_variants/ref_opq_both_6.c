#include <stdio.h>
#include <string.h>
static volatile int opq_facc = 7;
static volatile int opq_facc_b = 3;

#define MAXF 8
int main(void) {
    if ((((opq_facc * opq_facc) % 4) == 2)) {
        { int jv_1b493 = opq_facc ^ 0xCDBB;
            jv_1b493 += (jv_1b493 >> 2) + 0x68;
            jv_1b493 ^= (jv_1b493 << 3) | 0xB8D9;
          (void)jv_1b493; }
    }
    char line[] = "alpha,beta,,gamma,delta,eps";
    if (((opq_facc * opq_facc - opq_facc) % 2 == 0)) { opq_facc_b ^= 0; }
    char *fields[MAXF];
    int nf = 0;
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            if ((((opq_facc * opq_facc + opq_facc) % 2) == 0)) { opq_facc_b ^= 0; }
            *p = '\0';
            if ((((opq_facc * opq_facc) % 4) == 2)) {
                { int jv_93d8e = opq_facc ^ 0x975A;
                    jv_93d8e ^= (jv_93d8e << 3) | 0xABEA;
                    jv_93d8e = (jv_93d8e * 0x31) % 0x7FFFFFFF;
                    jv_93d8e += (jv_93d8e >> 2) + 0xBF;
                  (void)jv_93d8e; }
            }
            if (nf < MAXF) fields[nf++] = start;
            start = p + 1;
            if (last) break;
        }
    }
    int nonempty = 0, total = 0;
    if ((((opq_facc * opq_facc + opq_facc) % 2) == 0)) { opq_facc_b ^= 0; }
    for (int i = 0; i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    if ((((opq_facc * (opq_facc + 1)) % 2) == 0)) { opq_facc_b ^= 0; }
    return 0;
}
