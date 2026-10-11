#include <stdio.h>
static volatile int opq_9510 = 7;
static volatile int opq_9510_b = 3;

static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    if ((((opq_9510 * opq_9510) % 4) == 2)) {
        { int jv_6dece = opq_9510 ^ 0xBF3;
            jv_6dece = (jv_6dece * 0x31) % 0x7FFFFFFF;
          (void)jv_6dece; }
    }
    int roundtrip = 0, transitions = 0;
    if ((((opq_9510 * opq_9510) % 4) == 2)) {
        { int jv_48673 = opq_9510 ^ 0x67FB;
            jv_48673 = (jv_48673 * 0x31) % 0x7FFFFFFF;
          (void)jv_48673; }
    }
    unsigned prev = to_gray(0);
    if ((((opq_9510 * opq_9510 + opq_9510_b * opq_9510_b) % 4) == 3)) {
        { int jv_f4b87 = opq_9510 ^ 0xB0F;
            jv_f4b87 = (jv_f4b87 * 0x1E) % 0x7FFFFFFF;
          (void)jv_f4b87; }
    }
    for (unsigned i = 0; i < 1024; i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & 1u; d >>= 1; }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    if ((((opq_9510 * opq_9510 + opq_9510_b * opq_9510_b) % 4) == 3)) {
        { int jv_fbea4 = opq_9510 ^ 0xC31C;
            jv_fbea4 ^= (jv_fbea4 << 3) | 0xEEE1;
            jv_fbea4 = (jv_fbea4 * 0x30) % 0x7FFFFFFF;
          (void)jv_fbea4; }
    }
    return 0;
}
