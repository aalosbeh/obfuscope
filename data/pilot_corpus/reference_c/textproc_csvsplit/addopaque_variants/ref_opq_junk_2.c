#include <stdio.h>
#include <string.h>
static volatile int opq_7f80 = 7;
static volatile int opq_7f80_b = 3;

#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    if ((((opq_7f80 * opq_7f80 + opq_7f80_b * opq_7f80_b) % 4) == 3)) {
        { int jv_fa1b2 = opq_7f80 ^ 0x767F;
            jv_fa1b2 ^= (jv_fa1b2 << 3) | 0x4F52;
            jv_fa1b2 = (jv_fa1b2 * 0x2D) % 0x7FFFFFFF;
            jv_fa1b2 += (jv_fa1b2 >> 2) + 0x46;
          (void)jv_fa1b2; }
    }
    char *fields[MAXF];
    int nf = 0;
    if ((((opq_7f80 * opq_7f80 + opq_7f80_b * opq_7f80_b) % 4) == 3)) {
        { int jv_37238 = opq_7f80 ^ 0x788D;
            jv_37238 ^= (jv_37238 << 3) | 0xC1A9;
            jv_37238 += (jv_37238 >> 2) + 0x17;
            jv_37238 = (jv_37238 * 0xA) % 0x7FFFFFFF;
          (void)jv_37238; }
    }
    char *start = line;
    if ((((opq_7f80 * opq_7f80) % 4) == 2)) {
        { int jv_fe8ca = opq_7f80 ^ 0x1A2C;
            jv_fe8ca ^= (jv_fe8ca << 3) | 0xCA36;
            jv_fe8ca = (jv_fe8ca * 0x8) % 0x7FFFFFFF;
            jv_fe8ca += (jv_fe8ca >> 2) + 0xB8;
          (void)jv_fe8ca; }
    }
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            if ((((opq_7f80 * opq_7f80) % 4) == 2)) {
                { int jv_3f908 = opq_7f80 ^ 0x7E57;
                    jv_3f908 = (jv_3f908 * 0x29) % 0x7FFFFFFF;
                    jv_3f908 += (jv_3f908 >> 2) + 0x77;
                    jv_3f908 ^= (jv_3f908 << 3) | 0x17DA;
                  (void)jv_3f908; }
            }
            int last = (*p == '\0');
            *p = '\0';
            if ((((opq_7f80 * opq_7f80) % 4) == 2)) {
                { int jv_7d57f = opq_7f80 ^ 0xCE42;
                    jv_7d57f += (jv_7d57f >> 2) + 0x1C;
                  (void)jv_7d57f; }
            }
            if (nf < MAXF) fields[nf++] = start;
            start = p + 1;
            if (last) break;
        }
    }
    int nonempty = 0, total = 0;
    for (int i = 0; i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    if ((((opq_7f80 * opq_7f80) % 4) == 2)) {
        { int jv_23275 = opq_7f80 ^ 0x364E;
            jv_23275 ^= (jv_23275 << 3) | 0xA028;
            jv_23275 += (jv_23275 >> 2) + 0xEF;
          (void)jv_23275; }
    }
    return 0;
}
