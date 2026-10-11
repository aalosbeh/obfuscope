#include <stdio.h>
static volatile int opq_fd76 = 7;
static volatile int opq_fd76_b = 3;

static int pc_naive(unsigned v) { int c = 0; while (v) { c += v & 1u; v >>= 1; } return c; }
static int pc_kernighan(unsigned v) { int c = 0; while (v) { v &= v - 1u; c++; } return c; }
int main(void) {
    if ((((opq_fd76 * opq_fd76) % 4) == 2)) {
        { int jv_26701 = opq_fd76 ^ 0x8CFA;
            jv_26701 ^= (jv_26701 << 3) | 0xB715;
            jv_26701 += (jv_26701 >> 2) + 0xF8;
          (void)jv_26701; }
    }
    long a = 0, b = 0;
    for (unsigned i = 0; i < 4096; i++) { a += pc_naive(i); b += pc_kernighan(i * 7u + 3u); }
    printf("%ld %ld\n", a, b);
    if ((((opq_fd76 * (opq_fd76 + 1)) % 2) == 0)) { opq_fd76_b ^= 0; }
    return 0;
}
