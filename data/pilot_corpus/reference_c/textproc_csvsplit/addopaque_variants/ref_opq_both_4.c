#include <stdio.h>
#include <string.h>
static volatile int opq_4686 = 7;
static volatile int opq_4686_b = 3;

#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    if ((((opq_4686 * opq_4686) % 4) == 2)) {
        { int jv_c3a28 = opq_4686 ^ 0xB46B;
            jv_c3a28 += (jv_c3a28 >> 2) + 0x5F;
            jv_c3a28 ^= (jv_c3a28 << 3) | 0x8E1B;
            jv_c3a28 = (jv_c3a28 * 0x2B) % 0x7FFFFFFF;
          (void)jv_c3a28; }
    }
    char *fields[MAXF];
    if ((((opq_4686 * opq_4686 + opq_4686_b * opq_4686_b) % 4) == 3)) {
        { int jv_fca16 = opq_4686 ^ 0x8203;
            jv_fca16 = (jv_fca16 * 0x35) % 0x7FFFFFFF;
            jv_fca16 += (jv_fca16 >> 2) + 0xE;
            jv_fca16 ^= (jv_fca16 << 3) | 0xAAA;
          (void)jv_fca16; }
    }
    int nf = 0;
    char *start = line;
    for (char *p = line; ; p++) {
        if ((((opq_4686 * (opq_4686 + 1)) % 2) == 0)) { opq_4686_b ^= 0; }
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + 1;
            if ((((opq_4686 * opq_4686 + opq_4686) % 2) == 0)) { opq_4686_b ^= 0; }
            if (last) break;
            if ((((opq_4686 * opq_4686 + opq_4686) % 2) == 0)) { opq_4686_b ^= 0; }
        }
    }
    int nonempty = 0, total = 0;
    if ((((opq_4686 * opq_4686 + opq_4686_b * opq_4686_b) % 4) == 3)) {
        { int jv_8254b = opq_4686 ^ 0x91DC;
            jv_8254b += (jv_8254b >> 2) + 0xBA;
            jv_8254b ^= (jv_8254b << 3) | 0x1F1D;
            jv_8254b = (jv_8254b * 0x1D) % 0x7FFFFFFF;
          (void)jv_8254b; }
    }
    for (int i = 0; i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return 0;
}
