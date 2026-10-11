#include <stdio.h>
#include <string.h>
static volatile int opq_44bd = 7;
static volatile int opq_44bd_b = 3;

#define MAXF 8
int main(void) {
    if ((((opq_44bd * opq_44bd) % 4) == 2)) {
        { int jv_d0380 = opq_44bd ^ 0xC670;
            jv_d0380 += (jv_d0380 >> 2) + 0xB7;
            jv_d0380 ^= (jv_d0380 << 3) | 0xE59B;
            jv_d0380 = (jv_d0380 * 0x6) % 0x7FFFFFFF;
          (void)jv_d0380; }
    }
    char line[] = "alpha,beta,,gamma,delta,eps";
    if ((((opq_44bd * opq_44bd) % 4) == 2)) {
        { int jv_8ab06 = opq_44bd ^ 0xE82E;
            jv_8ab06 ^= (jv_8ab06 << 3) | 0xE87C;
            jv_8ab06 = (jv_8ab06 * 0x15) % 0x7FFFFFFF;
          (void)jv_8ab06; }
    }
    char *fields[MAXF];
    int nf = 0;
    char *start = line;
    if ((((opq_44bd * opq_44bd) % 4) == 2)) {
        { int jv_16815 = opq_44bd ^ 0xC3C0;
            jv_16815 = (jv_16815 * 0x2E) % 0x7FFFFFFF;
            jv_16815 += (jv_16815 >> 2) + 0xA8;
            jv_16815 ^= (jv_16815 << 3) | 0xF227;
          (void)jv_16815; }
    }
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            if ((((opq_44bd * opq_44bd + opq_44bd_b * opq_44bd_b) % 4) == 3)) {
                { int jv_d4da7 = opq_44bd ^ 0x9F0E;
                    jv_d4da7 ^= (jv_d4da7 << 3) | 0xF751;
                    jv_d4da7 += (jv_d4da7 >> 2) + 0xA5;
                    jv_d4da7 = (jv_d4da7 * 0x1C) % 0x7FFFFFFF;
                  (void)jv_d4da7; }
            }
            int last = (*p == '\0');
            if ((((opq_44bd * opq_44bd) % 4) == 2)) {
                { int jv_967b8 = opq_44bd ^ 0xE38B;
                    jv_967b8 += (jv_967b8 >> 2) + 0x62;
                    jv_967b8 = (jv_967b8 * 0x20) % 0x7FFFFFFF;
                    jv_967b8 ^= (jv_967b8 << 3) | 0x4C59;
                  (void)jv_967b8; }
            }
            *p = '\0';
            if ((((opq_44bd * opq_44bd) % 4) == 2)) {
                { int jv_fc55b = opq_44bd ^ 0xE917;
                    jv_fc55b = (jv_fc55b * 0x3E) % 0x7FFFFFFF;
                    jv_fc55b ^= (jv_fc55b << 3) | 0xEFE;
                    jv_fc55b += (jv_fc55b >> 2) + 0x2A;
                  (void)jv_fc55b; }
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
