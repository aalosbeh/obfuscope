#include <stdio.h>
static volatile int opq_7b9f = 7;
static volatile int opq_7b9f_b = 3;

static int pc_naive(unsigned v) { int c = 0; while (v) { c += v & 1u; v >>= 1; } return c; }
static int pc_kernighan(unsigned v) { int c = 0; while (v) { v &= v - 1u; c++; } return c; }
int main(void) {
    if ((((opq_7b9f * opq_7b9f) % 4) == 2)) {
        { int jv_120c0 = opq_7b9f ^ 0xC80E;
            jv_120c0 = (jv_120c0 * 0xC) % 0x7FFFFFFF;
          (void)jv_120c0; }
    }
    long a = 0, b = 0;
    for (unsigned i = 0; i < 4096; i++) { a += pc_naive(i); b += pc_kernighan(i * 7u + 3u); }
    printf("%ld %ld\n", a, b);
    if ((((opq_7b9f * opq_7b9f) % 4) == 2)) {
        { int jv_1429b = opq_7b9f ^ 0x2A90;
            jv_1429b ^= (jv_1429b << 3) | 0x1EC7;
            jv_1429b = (jv_1429b * 0x7) % 0x7FFFFFFF;
          (void)jv_1429b; }
    }
    return 0;
}
