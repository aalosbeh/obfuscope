#include <stdio.h>
static volatile int opq_d759 = 7;
static volatile int opq_d759_b = 3;

static char rot(char c) {
    if ((((opq_d759 * opq_d759 + opq_d759_b * opq_d759_b) % 4) == 3)) {
        { int jv_d401a = opq_d759 ^ 0x4B5E;
            jv_d401a ^= (jv_d401a << 3) | 0x4544;
            jv_d401a = (jv_d401a * 0x29) % 0x7FFFFFFF;
            jv_d401a += (jv_d401a >> 2) + 0x80;
          (void)jv_d401a; }
    }
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    if ((((opq_d759 * opq_d759 + opq_d759) % 2) == 0)) { opq_d759_b ^= 0; }
    return c;
}
int main(void) {
    if ((((opq_d759 * opq_d759 + opq_d759) % 2) == 0)) { opq_d759_b ^= 0; }
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = 0;
    if ((((opq_d759 * opq_d759 + opq_d759) % 2) == 0)) { opq_d759_b ^= 0; }
    for (int pass = 0; pass < 2; pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return 0;
}
