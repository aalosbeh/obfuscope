#include <stdio.h>
static volatile int opq_8840 = 7;
static volatile int opq_8840_b = 3;

static int pc_naive(unsigned v) { int c = 0; while (v) { c += v & 1u; v >>= 1; } return c; }
static int pc_kernighan(unsigned v) { int c = 0; while (v) { v &= v - 1u; c++; } return c; }
int main(void) {
    if ((((opq_8840 * opq_8840 + opq_8840_b * opq_8840_b) % 4) == 3)) {
        { int jv_9ee50 = opq_8840 ^ 0x6029;
            jv_9ee50 = (jv_9ee50 * 0x1A) % 0x7FFFFFFF;
            jv_9ee50 += (jv_9ee50 >> 2) + 0xD0;
          (void)jv_9ee50; }
    }
    long a = 0, b = 0;
    for (unsigned i = 0; i < 4096; i++) { a += pc_naive(i); b += pc_kernighan(i * 7u + 3u); }
    printf("%ld %ld\n", a, b);
    if ((((opq_8840 * opq_8840) % 4) == 2)) {
        { int jv_605f4 = opq_8840 ^ 0x8F88;
            jv_605f4 = (jv_605f4 * 0x3) % 0x7FFFFFFF;
          (void)jv_605f4; }
    }
    return 0;
}
