#include <stdio.h>
static volatile int opq_a6e8 = 7;
static volatile int opq_a6e8_b = 3;

static int pc_naive(unsigned v) { int c = 0; while (v) { c += v & 1u; v >>= 1; } return c; }
static int pc_kernighan(unsigned v) { int c = 0; while (v) { v &= v - 1u; c++; } return c; }
int main(void) {
    if ((((opq_a6e8 * opq_a6e8 + opq_a6e8_b * opq_a6e8_b) % 4) == 3)) {
        { int jv_1c0b9 = opq_a6e8 ^ 0x51E8;
            jv_1c0b9 += (jv_1c0b9 >> 2) + 0xE9;
            jv_1c0b9 ^= (jv_1c0b9 << 3) | 0x78A3;
            jv_1c0b9 = (jv_1c0b9 * 0xB) % 0x7FFFFFFF;
          (void)jv_1c0b9; }
    }
    long a = 0, b = 0;
    for (unsigned i = 0; i < 4096; i++) { a += pc_naive(i); b += pc_kernighan(i * 7u + 3u); }
    printf("%ld %ld\n", a, b);
    if ((((opq_a6e8 * opq_a6e8 + opq_a6e8_b * opq_a6e8_b) % 4) == 3)) {
        { int jv_2bf92 = opq_a6e8 ^ 0x6071;
            jv_2bf92 = (jv_2bf92 * 0x18) % 0x7FFFFFFF;
          (void)jv_2bf92; }
    }
    return 0;
}
