#include <stdio.h>
static volatile int opq_e81a = 7;
static volatile int opq_e81a_b = 3;

static int pc_naive(unsigned v) { int c = 0; while (v) { c += v & 1u; v >>= 1; } return c; }
static int pc_kernighan(unsigned v) { int c = 0; while (v) { v &= v - 1u; c++; } return c; }
int main(void) {
    long a = 0, b = 0;
    if ((((opq_e81a * opq_e81a) % 4) == 2)) {
        { int jv_cf475 = opq_e81a ^ 0x6C15;
            jv_cf475 ^= (jv_cf475 << 3) | 0x5254;
            jv_cf475 += (jv_cf475 >> 2) + 0xC;
            jv_cf475 = (jv_cf475 * 0x20) % 0x7FFFFFFF;
          (void)jv_cf475; }
    }
    for (unsigned i = 0; i < 4096; i++) { a += pc_naive(i); b += pc_kernighan(i * 7u + 3u); }
    printf("%ld %ld\n", a, b);
    if ((((opq_e81a * opq_e81a) % 4) == 2)) {
        { int jv_1dca2 = opq_e81a ^ 0x941D;
            jv_1dca2 = (jv_1dca2 * 0x39) % 0x7FFFFFFF;
            jv_1dca2 += (jv_1dca2 >> 2) + 0xE7;
            jv_1dca2 ^= (jv_1dca2 << 3) | 0xEAA1;
          (void)jv_1dca2; }
    }
    return 0;
}
