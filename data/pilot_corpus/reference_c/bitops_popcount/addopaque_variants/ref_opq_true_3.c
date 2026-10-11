#include <stdio.h>
static volatile int opq_4b74 = 7;
static volatile int opq_4b74_b = 3;

static int pc_naive(unsigned v) { int c = 0; while (v) { c += v & 1u; v >>= 1; } return c; }
static int pc_kernighan(unsigned v) { int c = 0; while (v) { v &= v - 1u; c++; } return c; }
int main(void) {
    long a = 0, b = 0;
    if ((((opq_4b74 * (opq_4b74 + 1)) % 2) == 0)) { opq_4b74_b ^= 0; }
    for (unsigned i = 0; i < 4096; i++) { a += pc_naive(i); b += pc_kernighan(i * 7u + 3u); }
    printf("%ld %ld\n", a, b);
    if ((((opq_4b74 * opq_4b74 + opq_4b74) % 2) == 0)) { opq_4b74_b ^= 0; }
    return 0;
}
