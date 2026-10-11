#include <stdio.h>
static volatile int opq_e976 = 7;
static volatile int opq_e976_b = 3;

static int pc_naive(unsigned v) { int c = 0; while (v) { c += v & 1u; v >>= 1; } return c; }
static int pc_kernighan(unsigned v) { int c = 0; while (v) { v &= v - 1u; c++; } return c; }
int main(void) {
    if ((((opq_e976 * opq_e976 + opq_e976_b * opq_e976_b) % 4) == 3)) {
        { int jv_53815 = opq_e976 ^ 0x6D0;
            jv_53815 = (jv_53815 * 0x2B) % 0x7FFFFFFF;
            jv_53815 += (jv_53815 >> 2) + 0xAB;
            jv_53815 ^= (jv_53815 << 3) | 0xAE37;
          (void)jv_53815; }
    }
    long a = 0, b = 0;
    for (unsigned i = 0; i < 4096; i++) { a += pc_naive(i); b += pc_kernighan(i * 7u + 3u); }
    printf("%ld %ld\n", a, b);
    if ((((opq_e976 * opq_e976) % 4) == 2)) {
        { int jv_d5c0f = opq_e976 ^ 0x8B98;
            jv_d5c0f += (jv_d5c0f >> 2) + 0xAC;
            jv_d5c0f ^= (jv_d5c0f << 3) | 0xDF74;
          (void)jv_d5c0f; }
    }
    return 0;
}
