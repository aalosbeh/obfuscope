#include <stdio.h>
static volatile int opq_2920 = 7;
static volatile int opq_2920_b = 3;

static int pc_naive(unsigned v) { int c = 0; while (v) { c += v & 1u; v >>= 1; } return c; }
static int pc_kernighan(unsigned v) { int c = 0; while (v) { v &= v - 1u; c++; } return c; }
int main(void) {
    if ((((opq_2920 * opq_2920) % 4) == 2)) {
        { int jv_f9d02 = opq_2920 ^ 0x9788;
            jv_f9d02 ^= (jv_f9d02 << 3) | 0x295;
          (void)jv_f9d02; }
    }
    long a = 0, b = 0;
    if ((((opq_2920 * (opq_2920 + 1)) % 2) == 0)) { opq_2920_b ^= 0; }
    for (unsigned i = 0; i < 4096; i++) { a += pc_naive(i); b += pc_kernighan(i * 7u + 3u); }
    printf("%ld %ld\n", a, b);
    return 0;
}
