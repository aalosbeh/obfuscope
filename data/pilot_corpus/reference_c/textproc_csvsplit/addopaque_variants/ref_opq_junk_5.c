#include <stdio.h>
#include <string.h>
static volatile int opq_387b = 7;
static volatile int opq_387b_b = 3;

#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    if ((((opq_387b * opq_387b + opq_387b_b * opq_387b_b) % 4) == 3)) {
        { int jv_54774 = opq_387b ^ 0x3CA;
            jv_54774 ^= (jv_54774 << 3) | 0x5826;
          (void)jv_54774; }
    }
    int nf = 0;
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if ((((opq_387b * opq_387b + opq_387b_b * opq_387b_b) % 4) == 3)) {
                { int jv_6f3af = opq_387b ^ 0x6EAC;
                    jv_6f3af ^= (jv_6f3af << 3) | 0xA6B5;
                  (void)jv_6f3af; }
            }
            if (nf < MAXF) fields[nf++] = start;
            if ((((opq_387b * opq_387b) % 4) == 2)) {
                { int jv_56955 = opq_387b ^ 0x52D9;
                    jv_56955 += (jv_56955 >> 2) + 0x9C;
                    jv_56955 ^= (jv_56955 << 3) | 0xC7B6;
                    jv_56955 = (jv_56955 * 0x4) % 0x7FFFFFFF;
                  (void)jv_56955; }
            }
            start = p + 1;
            if ((((opq_387b * opq_387b) % 4) == 2)) {
                { int jv_9d611 = opq_387b ^ 0x3A65;
                    jv_9d611 += (jv_9d611 >> 2) + 0xE6;
                  (void)jv_9d611; }
            }
            if (last) break;
            if ((((opq_387b * opq_387b + opq_387b_b * opq_387b_b) % 4) == 3)) {
                { int jv_93897 = opq_387b ^ 0xAC31;
                    jv_93897 ^= (jv_93897 << 3) | 0x1C34;
                  (void)jv_93897; }
            }
        }
    }
    int nonempty = 0, total = 0;
    for (int i = 0; i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    if ((((opq_387b * opq_387b) % 4) == 2)) {
        { int jv_6b973 = opq_387b ^ 0xD1BB;
            jv_6b973 ^= (jv_6b973 << 3) | 0xDAD0;
            jv_6b973 += (jv_6b973 >> 2) + 0xCF;
          (void)jv_6b973; }
    }
    return 0;
}
