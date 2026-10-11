#include <stdio.h>
#include <string.h>
static volatile int opq_7cce = 7;
static volatile int opq_7cce_b = 3;

#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    if ((((opq_7cce * (opq_7cce + 1)) % 2) == 0)) { opq_7cce_b ^= 0; }
    int nf = 0;
    if ((((opq_7cce * opq_7cce + opq_7cce) % 2) == 0)) { opq_7cce_b ^= 0; }
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            if ((((opq_7cce * opq_7cce + opq_7cce_b * opq_7cce_b) % 4) == 3)) {
                { int jv_8c906 = opq_7cce ^ 0x8176;
                    jv_8c906 ^= (jv_8c906 << 3) | 0xB9D5;
                    jv_8c906 += (jv_8c906 >> 2) + 0x51;
                  (void)jv_8c906; }
            }
            start = p + 1;
            if (((opq_7cce * opq_7cce - opq_7cce) % 2 == 0)) { opq_7cce_b ^= 0; }
            if (last) break;
            if ((((opq_7cce * opq_7cce) % 4) == 2)) {
                { int jv_da499 = opq_7cce ^ 0x71C1;
                    jv_da499 = (jv_da499 * 0x31) % 0x7FFFFFFF;
                    jv_da499 ^= (jv_da499 << 3) | 0x5B94;
                    jv_da499 += (jv_da499 >> 2) + 0xF7;
                  (void)jv_da499; }
            }
        }
    }
    int nonempty = 0, total = 0;
    for (int i = 0; i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    if ((((opq_7cce * opq_7cce + opq_7cce_b * opq_7cce_b) % 4) == 3)) {
        { int jv_4e074 = opq_7cce ^ 0xE6FC;
            jv_4e074 ^= (jv_4e074 << 3) | 0x1399;
            jv_4e074 += (jv_4e074 >> 2) + 0x58;
          (void)jv_4e074; }
    }
    return 0;
}
