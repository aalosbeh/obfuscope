#include <stdio.h>
#include <string.h>
static volatile int opq_c241 = 7;
static volatile int opq_c241_b = 3;

#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    if ((((opq_c241 * opq_c241) % 4) == 2)) {
        { int jv_658e7 = opq_c241 ^ 0x18E0;
            jv_658e7 = (jv_658e7 * 0x13) % 0x7FFFFFFF;
            jv_658e7 += (jv_658e7 >> 2) + 0x8F;
          (void)jv_658e7; }
    }
    char *fields[MAXF];
    int nf = 0;
    if (((opq_c241 * opq_c241 - opq_c241) % 2 == 0)) { opq_c241_b ^= 0; }
    char *start = line;
    if ((((opq_c241 * opq_c241) % 4) == 2)) {
        { int jv_a4fea = opq_c241 ^ 0x601E;
            jv_a4fea = (jv_a4fea * 0x10) % 0x7FFFFFFF;
            jv_a4fea ^= (jv_a4fea << 3) | 0x7292;
          (void)jv_a4fea; }
    }
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            if ((((opq_c241 * (opq_c241 + 1)) % 2) == 0)) { opq_c241_b ^= 0; }
            int last = (*p == '\0');
            if (((opq_c241 * opq_c241 - opq_c241) % 2 == 0)) { opq_c241_b ^= 0; }
            *p = '\0';
            if ((((opq_c241 * opq_c241 + opq_c241_b * opq_c241_b) % 4) == 3)) {
                { int jv_3f18b = opq_c241 ^ 0x386E;
                    jv_3f18b = (jv_3f18b * 0x1E) % 0x7FFFFFFF;
                    jv_3f18b ^= (jv_3f18b << 3) | 0x5F0;
                    jv_3f18b += (jv_3f18b >> 2) + 0xE;
                  (void)jv_3f18b; }
            }
            if (nf < MAXF) fields[nf++] = start;
            start = p + 1;
            if (last) break;
        }
    }
    int nonempty = 0, total = 0;
    for (int i = 0; i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return 0;
}
