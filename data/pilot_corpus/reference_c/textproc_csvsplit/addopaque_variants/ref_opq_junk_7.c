#include <stdio.h>
#include <string.h>
static volatile int opq_1e37 = 7;
static volatile int opq_1e37_b = 3;

#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    if ((((opq_1e37 * opq_1e37 + opq_1e37_b * opq_1e37_b) % 4) == 3)) {
        { int jv_f0134 = opq_1e37 ^ 0x127;
            jv_f0134 ^= (jv_f0134 << 3) | 0xC4F7;
          (void)jv_f0134; }
    }
    int nf = 0;
    char *start = line;
    if ((((opq_1e37 * opq_1e37 + opq_1e37_b * opq_1e37_b) % 4) == 3)) {
        { int jv_cab9c = opq_1e37 ^ 0x9302;
            jv_cab9c = (jv_cab9c * 0x28) % 0x7FFFFFFF;
            jv_cab9c += (jv_cab9c >> 2) + 0xC9;
          (void)jv_cab9c; }
    }
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            if ((((opq_1e37 * opq_1e37 + opq_1e37_b * opq_1e37_b) % 4) == 3)) {
                { int jv_3b31d = opq_1e37 ^ 0x8528;
                    jv_3b31d = (jv_3b31d * 0x1B) % 0x7FFFFFFF;
                    jv_3b31d ^= (jv_3b31d << 3) | 0xF820;
                  (void)jv_3b31d; }
            }
            int last = (*p == '\0');
            *p = '\0';
            if ((((opq_1e37 * opq_1e37 + opq_1e37_b * opq_1e37_b) % 4) == 3)) {
                { int jv_1015b = opq_1e37 ^ 0xD44C;
                    jv_1015b ^= (jv_1015b << 3) | 0xAD48;
                  (void)jv_1015b; }
            }
            if (nf < MAXF) fields[nf++] = start;
            start = p + 1;
            if (last) break;
            if ((((opq_1e37 * opq_1e37) % 4) == 2)) {
                { int jv_8b820 = opq_1e37 ^ 0x106D;
                    jv_8b820 = (jv_8b820 * 0x3D) % 0x7FFFFFFF;
                    jv_8b820 += (jv_8b820 >> 2) + 0x28;
                    jv_8b820 ^= (jv_8b820 << 3) | 0x7860;
                  (void)jv_8b820; }
            }
        }
    }
    int nonempty = 0, total = 0;
    for (int i = 0; i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    if ((((opq_1e37 * opq_1e37) % 4) == 2)) {
        { int jv_44323 = opq_1e37 ^ 0x92D1;
            jv_44323 += (jv_44323 >> 2) + 0xBE;
          (void)jv_44323; }
    }
    return 0;
}
