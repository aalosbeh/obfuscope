#include <stdio.h>
static volatile int opq_bfbf = 7;
static volatile int opq_bfbf_b = 3;

static int pc_naive(unsigned v) { int c = 0; while (v) { c += v & 1u; v >>= 1; } return c; }
static int pc_kernighan(unsigned v) { int c = 0; while (v) { v &= v - 1u; c++; } return c; }
int main(void) {
    if ((((opq_bfbf * opq_bfbf + opq_bfbf_b * opq_bfbf_b) % 4) == 3)) {
        { int jv_9cb19 = opq_bfbf ^ 0x2937;
            jv_9cb19 = (jv_9cb19 * 0x32) % 0x7FFFFFFF;
            jv_9cb19 ^= (jv_9cb19 << 3) | 0xE39C;
          (void)jv_9cb19; }
    }
    long a = 0, b = 0;
    if ((((opq_bfbf * opq_bfbf) % 4) == 2)) {
        { int jv_366cb = opq_bfbf ^ 0x9E0C;
            jv_366cb ^= (jv_366cb << 3) | 0x2E9C;
          (void)jv_366cb; }
    }
    for (unsigned i = 0; i < 4096; i++) { a += pc_naive(i); b += pc_kernighan(i * 7u + 3u); }
    printf("%ld %ld\n", a, b);
    return 0;
}
