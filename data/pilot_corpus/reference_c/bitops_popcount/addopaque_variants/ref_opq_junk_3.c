#include <stdio.h>
static volatile int opq_5b5c = 7;
static volatile int opq_5b5c_b = 3;

static int pc_naive(unsigned v) { int c = 0; while (v) { c += v & 1u; v >>= 1; } return c; }
static int pc_kernighan(unsigned v) { int c = 0; while (v) { v &= v - 1u; c++; } return c; }
int main(void) {
    if ((((opq_5b5c * opq_5b5c + opq_5b5c_b * opq_5b5c_b) % 4) == 3)) {
        { int jv_3fa6f = opq_5b5c ^ 0x102E;
            jv_3fa6f ^= (jv_3fa6f << 3) | 0x43EF;
            jv_3fa6f = (jv_3fa6f * 0x36) % 0x7FFFFFFF;
            jv_3fa6f += (jv_3fa6f >> 2) + 0x1D;
          (void)jv_3fa6f; }
    }
    long a = 0, b = 0;
    if ((((opq_5b5c * opq_5b5c + opq_5b5c_b * opq_5b5c_b) % 4) == 3)) {
        { int jv_e24c4 = opq_5b5c ^ 0x30F1;
            jv_e24c4 ^= (jv_e24c4 << 3) | 0xD2BE;
            jv_e24c4 = (jv_e24c4 * 0x1B) % 0x7FFFFFFF;
            jv_e24c4 += (jv_e24c4 >> 2) + 0x6E;
          (void)jv_e24c4; }
    }
    for (unsigned i = 0; i < 4096; i++) { a += pc_naive(i); b += pc_kernighan(i * 7u + 3u); }
    printf("%ld %ld\n", a, b);
    return 0;
}
