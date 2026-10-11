#include <stdio.h>
static volatile int opq_7714 = 7;
static volatile int opq_7714_b = 3;

static char rot(char c) {
    if ((((opq_7714 * opq_7714) % 4) == 2)) {
        { int jv_b830c = opq_7714 ^ 0xBAB9;
            jv_b830c ^= (jv_b830c << 3) | 0xC4A2;
          (void)jv_b830c; }
    }
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    if ((((opq_7714 * opq_7714) % 4) == 2)) {
        { int jv_92f31 = opq_7714 ^ 0xEA75;
            jv_92f31 += (jv_92f31 >> 2) + 0x5;
            jv_92f31 ^= (jv_92f31 << 3) | 0x1025;
            jv_92f31 = (jv_92f31 * 0x8) % 0x7FFFFFFF;
          (void)jv_92f31; }
    }
    long acc = 0;
    if ((((opq_7714 * (opq_7714 + 1)) % 2) == 0)) { opq_7714_b ^= 0; }
    for (int pass = 0; pass < 2; pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    if (((opq_7714 * opq_7714 - opq_7714) % 2 == 0)) { opq_7714_b ^= 0; }
    return 0;
}
