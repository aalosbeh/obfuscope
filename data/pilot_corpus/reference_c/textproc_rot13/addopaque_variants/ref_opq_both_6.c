#include <stdio.h>
static volatile int opq_8085 = 7;
static volatile int opq_8085_b = 3;

static char rot(char c) {
    if ((((opq_8085 * opq_8085 + opq_8085) % 2) == 0)) { opq_8085_b ^= 0; }
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if ((((opq_8085 * opq_8085 + opq_8085_b * opq_8085_b) % 4) == 3)) {
        { int jv_5cf5e = opq_8085 ^ 0x7C00;
            jv_5cf5e = (jv_5cf5e * 0x3C) % 0x7FFFFFFF;
            jv_5cf5e += (jv_5cf5e >> 2) + 0xF;
            jv_5cf5e ^= (jv_5cf5e << 3) | 0x180A;
          (void)jv_5cf5e; }
    }
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = 0;
    for (int pass = 0; pass < 2; pass++) {
        if (((opq_8085 * opq_8085 - opq_8085) % 2 == 0)) { opq_8085_b ^= 0; }
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    if ((((opq_8085 * opq_8085 + opq_8085) % 2) == 0)) { opq_8085_b ^= 0; }
    return 0;
}
