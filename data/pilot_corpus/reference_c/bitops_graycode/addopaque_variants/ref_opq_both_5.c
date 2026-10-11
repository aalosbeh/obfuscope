#include <stdio.h>
static volatile int opq_a06d = 7;
static volatile int opq_a06d_b = 3;

static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    if ((((opq_a06d * opq_a06d + opq_a06d) % 2) == 0)) { opq_a06d_b ^= 0; }
    int roundtrip = 0, transitions = 0;
    unsigned prev = to_gray(0);
    if (((opq_a06d * opq_a06d - opq_a06d) % 2 == 0)) { opq_a06d_b ^= 0; }
    for (unsigned i = 0; i < 1024; i++) {
        if ((((opq_a06d * opq_a06d + opq_a06d_b * opq_a06d_b) % 4) == 3)) {
            { int jv_d5975 = opq_a06d ^ 0xAB63;
                jv_d5975 += (jv_d5975 >> 2) + 0xAF;
                jv_d5975 = (jv_d5975 * 0x15) % 0x7FFFFFFF;
                jv_d5975 ^= (jv_d5975 << 3) | 0xE57D;
              (void)jv_d5975; }
        }
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & 1u; d >>= 1; }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    if ((((opq_a06d * opq_a06d + opq_a06d_b * opq_a06d_b) % 4) == 3)) {
        { int jv_983c8 = opq_a06d ^ 0x823E;
            jv_983c8 += (jv_983c8 >> 2) + 0x74;
            jv_983c8 = (jv_983c8 * 0x6) % 0x7FFFFFFF;
          (void)jv_983c8; }
    }
    return 0;
}
