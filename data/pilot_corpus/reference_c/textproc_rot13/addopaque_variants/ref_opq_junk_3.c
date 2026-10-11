#include <stdio.h>
static volatile int opq_167c = 7;
static volatile int opq_167c_b = 3;

static char rot(char c) {
    if ((((opq_167c * opq_167c + opq_167c_b * opq_167c_b) % 4) == 3)) {
        { int jv_2c2f3 = opq_167c ^ 0x2CB;
            jv_2c2f3 = (jv_2c2f3 * 0x8) % 0x7FFFFFFF;
            jv_2c2f3 ^= (jv_2c2f3 << 3) | 0xEC45;
            jv_2c2f3 += (jv_2c2f3 >> 2) + 0xD2;
          (void)jv_2c2f3; }
    }
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if ((((opq_167c * opq_167c + opq_167c_b * opq_167c_b) % 4) == 3)) {
        { int jv_5a921 = opq_167c ^ 0x180E;
            jv_5a921 = (jv_5a921 * 0xA) % 0x7FFFFFFF;
            jv_5a921 ^= (jv_5a921 << 3) | 0xAE36;
          (void)jv_5a921; }
    }
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    if ((((opq_167c * opq_167c) % 4) == 2)) {
        { int jv_55495 = opq_167c ^ 0xCA67;
            jv_55495 ^= (jv_55495 << 3) | 0xF7C2;
            jv_55495 += (jv_55495 >> 2) + 0x76;
            jv_55495 = (jv_55495 * 0x19) % 0x7FFFFFFF;
          (void)jv_55495; }
    }
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    if ((((opq_167c * opq_167c) % 4) == 2)) {
        { int jv_ca55d = opq_167c ^ 0x3C66;
            jv_ca55d = (jv_ca55d * 0x13) % 0x7FFFFFFF;
            jv_ca55d += (jv_ca55d >> 2) + 0xED;
            jv_ca55d ^= (jv_ca55d << 3) | 0xF8AE;
          (void)jv_ca55d; }
    }
    long acc = 0;
    for (int pass = 0; pass < 2; pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return 0;
}
