#include <stdio.h>
static volatile int opq_b0a1 = 7;
static volatile int opq_b0a1_b = 3;

static int pc_naive(unsigned v) { int c = 0; while (v) { c += v & 1u; v >>= 1; } return c; }
static int pc_kernighan(unsigned v) { int c = 0; while (v) { v &= v - 1u; c++; } return c; }
int main(void) {
    if ((((opq_b0a1 * opq_b0a1) % 4) == 2)) {
        { int jv_23346 = opq_b0a1 ^ 0x23FB;
            jv_23346 += (jv_23346 >> 2) + 0xE8;
            jv_23346 = (jv_23346 * 0x6) % 0x7FFFFFFF;
          (void)jv_23346; }
    }
    long a = 0, b = 0;
    if ((((opq_b0a1 * (opq_b0a1 + 1)) % 2) == 0)) { opq_b0a1_b ^= 0; }
    for (unsigned i = 0; i < 4096; i++) { a += pc_naive(i); b += pc_kernighan(i * 7u + 3u); }
    printf("%ld %ld\n", a, b);
    return 0;
}
