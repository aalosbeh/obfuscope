#include <stdio.h>
static volatile int opq_efd8 = 7;
static volatile int opq_efd8_b = 3;

static char rot(char c) {
    if ((((opq_efd8 * opq_efd8) % 4) == 2)) {
        { int jv_825c3 = opq_efd8 ^ 0x2134;
            jv_825c3 += (jv_825c3 >> 2) + 0x3E;
          (void)jv_825c3; }
    }
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    if ((((opq_efd8 * opq_efd8 + opq_efd8_b * opq_efd8_b) % 4) == 3)) {
        { int jv_ed57a = opq_efd8 ^ 0x2A3C;
            jv_ed57a ^= (jv_ed57a << 3) | 0xB866;
          (void)jv_ed57a; }
    }
    char buf[] = "Attack At Dawn, Bring Supplies!";
    if ((((opq_efd8 * opq_efd8 + opq_efd8_b * opq_efd8_b) % 4) == 3)) {
        { int jv_5d14b = opq_efd8 ^ 0x420A;
            jv_5d14b ^= (jv_5d14b << 3) | 0x3989;
          (void)jv_5d14b; }
    }
    long acc = 0;
    for (int pass = 0; pass < 2; pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    if ((((opq_efd8 * opq_efd8 + opq_efd8_b * opq_efd8_b) % 4) == 3)) {
        { int jv_bcb5e = opq_efd8 ^ 0x655C;
            jv_bcb5e += (jv_bcb5e >> 2) + 0xDB;
            jv_bcb5e ^= (jv_bcb5e << 3) | 0x1FC;
            jv_bcb5e = (jv_bcb5e * 0x22) % 0x7FFFFFFF;
          (void)jv_bcb5e; }
    }
    return 0;
}
