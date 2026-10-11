#include <stdio.h>
static volatile int opq_21dd = 7;
static volatile int opq_21dd_b = 3;

static int pc_naive(unsigned v) { int c = 0; while (v) { c += v & 1u; v >>= 1; } return c; }
static int pc_kernighan(unsigned v) { int c = 0; while (v) { v &= v - 1u; c++; } return c; }
int main(void) {
    long a = 0, b = 0;
    if ((((opq_21dd * opq_21dd + opq_21dd_b * opq_21dd_b) % 4) == 3)) {
        { int jv_4f618 = opq_21dd ^ 0x8DDA;
            jv_4f618 += (jv_4f618 >> 2) + 0x60;
            jv_4f618 ^= (jv_4f618 << 3) | 0xC506;
            jv_4f618 = (jv_4f618 * 0x13) % 0x7FFFFFFF;
          (void)jv_4f618; }
    }
    for (unsigned i = 0; i < 4096; i++) { a += pc_naive(i); b += pc_kernighan(i * 7u + 3u); }
    printf("%ld %ld\n", a, b);
    if ((((opq_21dd * opq_21dd + opq_21dd_b * opq_21dd_b) % 4) == 3)) {
        { int jv_d73f9 = opq_21dd ^ 0xE7;
            jv_d73f9 += (jv_d73f9 >> 2) + 0x8A;
            jv_d73f9 ^= (jv_d73f9 << 3) | 0x7B8D;
          (void)jv_d73f9; }
    }
    return 0;
}
