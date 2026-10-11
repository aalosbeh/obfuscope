#include <stdio.h>
static volatile int opq_1082 = 7;
static volatile int opq_1082_b = 3;

static int pc_naive(unsigned v) { int c = 0; while (v) { c += v & 1u; v >>= 1; } return c; }
static int pc_kernighan(unsigned v) { int c = 0; while (v) { v &= v - 1u; c++; } return c; }
int main(void) {
    long a = 0, b = 0;
    if ((((opq_1082 * opq_1082) % 4) == 2)) {
        { int jv_7661d = opq_1082 ^ 0x7C9B;
            jv_7661d = (jv_7661d * 0x1F) % 0x7FFFFFFF;
            jv_7661d += (jv_7661d >> 2) + 0x22;
            jv_7661d ^= (jv_7661d << 3) | 0xD5ED;
          (void)jv_7661d; }
    }
    for (unsigned i = 0; i < 4096; i++) { a += pc_naive(i); b += pc_kernighan(i * 7u + 3u); }
    printf("%ld %ld\n", a, b);
    if ((((opq_1082 * opq_1082) % 4) == 2)) {
        { int jv_8cdc4 = opq_1082 ^ 0xEA81;
            jv_8cdc4 = (jv_8cdc4 * 0x27) % 0x7FFFFFFF;
            jv_8cdc4 += (jv_8cdc4 >> 2) + 0x7D;
          (void)jv_8cdc4; }
    }
    return 0;
}
