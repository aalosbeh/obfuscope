#include <stdio.h>
#include <string.h>
static volatile int opq_e3ef = 7;
static volatile int opq_e3ef_b = 3;

#define MAXF 8
int main(void) {
    if ((((opq_e3ef * opq_e3ef) % 4) == 2)) {
        { int jv_76a30 = opq_e3ef ^ 0xE52C;
            jv_76a30 ^= (jv_76a30 << 3) | 0xA686;
          (void)jv_76a30; }
    }
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = 0;
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            if ((((opq_e3ef * opq_e3ef + opq_e3ef_b * opq_e3ef_b) % 4) == 3)) {
                { int jv_17a8c = opq_e3ef ^ 0xCE48;
                    jv_17a8c ^= (jv_17a8c << 3) | 0xBFF4;
                    jv_17a8c = (jv_17a8c * 0xB) % 0x7FFFFFFF;
                    jv_17a8c += (jv_17a8c >> 2) + 0x5;
                  (void)jv_17a8c; }
            }
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + 1;
            if ((((opq_e3ef * opq_e3ef + opq_e3ef_b * opq_e3ef_b) % 4) == 3)) {
                { int jv_ee7f8 = opq_e3ef ^ 0x2336;
                    jv_ee7f8 += (jv_ee7f8 >> 2) + 0xF;
                    jv_ee7f8 ^= (jv_ee7f8 << 3) | 0xF58;
                  (void)jv_ee7f8; }
            }
            if (last) break;
            if ((((opq_e3ef * opq_e3ef) % 4) == 2)) {
                { int jv_ce9ea = opq_e3ef ^ 0xF6CC;
                    jv_ce9ea += (jv_ce9ea >> 2) + 0x99;
                  (void)jv_ce9ea; }
            }
        }
    }
    int nonempty = 0, total = 0;
    if ((((opq_e3ef * opq_e3ef) % 4) == 2)) {
        { int jv_c6e6b = opq_e3ef ^ 0x8A62;
            jv_c6e6b ^= (jv_c6e6b << 3) | 0x7E31;
            jv_c6e6b += (jv_c6e6b >> 2) + 0xA4;
          (void)jv_c6e6b; }
    }
    for (int i = 0; i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    if ((((opq_e3ef * opq_e3ef) % 4) == 2)) {
        { int jv_d8ed7 = opq_e3ef ^ 0x9B46;
            jv_d8ed7 = (jv_d8ed7 * 0x33) % 0x7FFFFFFF;
          (void)jv_d8ed7; }
    }
    return 0;
}
