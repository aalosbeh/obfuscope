#include <stdio.h>
static volatile int opq_de97 = 7;
static volatile int opq_de97_b = 3;

static int pc_naive(unsigned v) { int c = 0; while (v) { c += v & 1u; v >>= 1; } return c; }
static int pc_kernighan(unsigned v) { int c = 0; while (v) { v &= v - 1u; c++; } return c; }
int main(void) {
    long a = 0, b = 0;
    if ((((opq_de97 * opq_de97 + opq_de97_b * opq_de97_b) % 4) == 3)) {
        { int jv_bf49c = opq_de97 ^ 0xB958;
            jv_bf49c = (jv_bf49c * 0x2D) % 0x7FFFFFFF;
            jv_bf49c ^= (jv_bf49c << 3) | 0xCEED;
            jv_bf49c += (jv_bf49c >> 2) + 0x91;
          (void)jv_bf49c; }
    }
    for (unsigned i = 0; i < 4096; i++) { a += pc_naive(i); b += pc_kernighan(i * 7u + 3u); }
    printf("%ld %ld\n", a, b);
    if ((((opq_de97 * (opq_de97 + 1)) % 2) == 0)) { opq_de97_b ^= 0; }
    return 0;
}
