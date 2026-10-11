#include <stdio.h>
#include <string.h>
static volatile int opq_d90d = 7;
static volatile int opq_d90d_b = 3;

#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    if ((((opq_d90d * opq_d90d + opq_d90d_b * opq_d90d_b) % 4) == 3)) {
        { int jv_a12d4 = opq_d90d ^ 0x2596;
            jv_a12d4 = (jv_a12d4 * 0xA) % 0x7FFFFFFF;
          (void)jv_a12d4; }
    }
    char *fields[MAXF];
    if ((((opq_d90d * opq_d90d + opq_d90d_b * opq_d90d_b) % 4) == 3)) {
        { int jv_884dc = opq_d90d ^ 0xD09E;
            jv_884dc = (jv_884dc * 0xD) % 0x7FFFFFFF;
          (void)jv_884dc; }
    }
    int nf = 0;
    char *start = line;
    if ((((opq_d90d * opq_d90d) % 4) == 2)) {
        { int jv_d0d7d = opq_d90d ^ 0x6245;
            jv_d0d7d ^= (jv_d0d7d << 3) | 0x6523;
            jv_d0d7d = (jv_d0d7d * 0x3C) % 0x7FFFFFFF;
          (void)jv_d0d7d; }
    }
    for (char *p = line; ; p++) {
        if ((((opq_d90d * opq_d90d + opq_d90d_b * opq_d90d_b) % 4) == 3)) {
            { int jv_90707 = opq_d90d ^ 0x5A0F;
                jv_90707 ^= (jv_90707 << 3) | 0xC9C;
              (void)jv_90707; }
        }
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            if ((((opq_d90d * opq_d90d) % 4) == 2)) {
                { int jv_4f6c1 = opq_d90d ^ 0xDFE9;
                    jv_4f6c1 = (jv_4f6c1 * 0x24) % 0x7FFFFFFF;
                  (void)jv_4f6c1; }
            }
            start = p + 1;
            if (last) break;
        }
    }
    int nonempty = 0, total = 0;
    for (int i = 0; i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    if ((((opq_d90d * opq_d90d + opq_d90d_b * opq_d90d_b) % 4) == 3)) {
        { int jv_92d93 = opq_d90d ^ 0xD6B4;
            jv_92d93 += (jv_92d93 >> 2) + 0xCD;
          (void)jv_92d93; }
    }
    return 0;
}
