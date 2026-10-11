#include <stdio.h>
static volatile int opq_1877 = 7;
static volatile int opq_1877_b = 3;

static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    if ((((opq_1877 * opq_1877) % 4) == 2)) {
        { int jv_d9001 = opq_1877 ^ 0xA30F;
            jv_d9001 = (jv_d9001 * 0x1D) % 0x7FFFFFFF;
            jv_d9001 ^= (jv_d9001 << 3) | 0x316E;
          (void)jv_d9001; }
    }
    return c;
}
int main(void) {
    if ((((opq_1877 * opq_1877 + opq_1877_b * opq_1877_b) % 4) == 3)) {
        { int jv_ee4a5 = opq_1877 ^ 0x2B9D;
            jv_ee4a5 ^= (jv_ee4a5 << 3) | 0x2697;
            jv_ee4a5 = (jv_ee4a5 * 0x18) % 0x7FFFFFFF;
            jv_ee4a5 += (jv_ee4a5 >> 2) + 0x31;
          (void)jv_ee4a5; }
    }
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = 0;
    if ((((opq_1877 * opq_1877) % 4) == 2)) {
        { int jv_be212 = opq_1877 ^ 0x8F36;
            jv_be212 += (jv_be212 >> 2) + 0x75;
          (void)jv_be212; }
    }
    for (int pass = 0; pass < 2; pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    if ((((opq_1877 * opq_1877) % 4) == 2)) {
        { int jv_fae5b = opq_1877 ^ 0x64D7;
            jv_fae5b += (jv_fae5b >> 2) + 0x48;
            jv_fae5b = (jv_fae5b * 0x11) % 0x7FFFFFFF;
            jv_fae5b ^= (jv_fae5b << 3) | 0x4D98;
          (void)jv_fae5b; }
    }
    return 0;
}
