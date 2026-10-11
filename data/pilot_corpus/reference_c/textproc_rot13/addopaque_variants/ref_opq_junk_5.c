#include <stdio.h>
static volatile int opq_4535 = 7;
static volatile int opq_4535_b = 3;

static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    if ((((opq_4535 * opq_4535 + opq_4535_b * opq_4535_b) % 4) == 3)) {
        { int jv_69751 = opq_4535 ^ 0x37A;
            jv_69751 ^= (jv_69751 << 3) | 0xF433;
            jv_69751 = (jv_69751 * 0x15) % 0x7FFFFFFF;
            jv_69751 += (jv_69751 >> 2) + 0x1D;
          (void)jv_69751; }
    }
    long acc = 0;
    if ((((opq_4535 * opq_4535) % 4) == 2)) {
        { int jv_6be01 = opq_4535 ^ 0xB09E;
            jv_6be01 ^= (jv_6be01 << 3) | 0x479F;
            jv_6be01 = (jv_6be01 * 0x39) % 0x7FFFFFFF;
            jv_6be01 += (jv_6be01 >> 2) + 0x1D;
          (void)jv_6be01; }
    }
    for (int pass = 0; pass < 2; pass++) {
        if ((((opq_4535 * opq_4535) % 4) == 2)) {
            { int jv_17ee7 = opq_4535 ^ 0xC48E;
                jv_17ee7 += (jv_17ee7 >> 2) + 0x1F;
              (void)jv_17ee7; }
        }
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    if ((((opq_4535 * opq_4535) % 4) == 2)) {
        { int jv_16332 = opq_4535 ^ 0x552E;
            jv_16332 += (jv_16332 >> 2) + 0x4;
            jv_16332 ^= (jv_16332 << 3) | 0xAE01;
          (void)jv_16332; }
    }
    return 0;
}
