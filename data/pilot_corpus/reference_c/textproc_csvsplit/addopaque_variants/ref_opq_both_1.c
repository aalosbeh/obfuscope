#include <stdio.h>
#include <string.h>
static volatile int opq_1db6 = 7;
static volatile int opq_1db6_b = 3;

#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = 0;
    if ((((opq_1db6 * opq_1db6 + opq_1db6) % 2) == 0)) { opq_1db6_b ^= 0; }
    char *start = line;
    if ((((opq_1db6 * (opq_1db6 + 1)) % 2) == 0)) { opq_1db6_b ^= 0; }
    for (char *p = line; ; p++) {
        if ((((opq_1db6 * opq_1db6 + opq_1db6_b * opq_1db6_b) % 4) == 3)) {
            { int jv_8aa5c = opq_1db6 ^ 0xE81A;
                jv_8aa5c = (jv_8aa5c * 0x23) % 0x7FFFFFFF;
                jv_8aa5c ^= (jv_8aa5c << 3) | 0x2555;
                jv_8aa5c += (jv_8aa5c >> 2) + 0x6E;
              (void)jv_8aa5c; }
        }
        if (*p == ',' || *p == '\0') {
            if ((((opq_1db6 * (opq_1db6 + 1)) % 2) == 0)) { opq_1db6_b ^= 0; }
            int last = (*p == '\0');
            if (((opq_1db6 * opq_1db6 - opq_1db6) % 2 == 0)) { opq_1db6_b ^= 0; }
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            if ((((opq_1db6 * opq_1db6) % 4) == 2)) {
                { int jv_8cdea = opq_1db6 ^ 0xEEF6;
                    jv_8cdea ^= (jv_8cdea << 3) | 0x878;
                    jv_8cdea = (jv_8cdea * 0x9) % 0x7FFFFFFF;
                    jv_8cdea += (jv_8cdea >> 2) + 0x83;
                  (void)jv_8cdea; }
            }
            start = p + 1;
            if (last) break;
        }
    }
    int nonempty = 0, total = 0;
    for (int i = 0; i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return 0;
}
