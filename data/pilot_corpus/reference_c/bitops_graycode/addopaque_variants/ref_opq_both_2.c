#include <stdio.h>
static volatile int opq_82bf = 7;
static volatile int opq_82bf_b = 3;

static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    int roundtrip = 0, transitions = 0;
    if ((((opq_82bf * opq_82bf) % 4) == 2)) {
        { int jv_8ec30 = opq_82bf ^ 0x9932;
            jv_8ec30 += (jv_8ec30 >> 2) + 0x89;
            jv_8ec30 ^= (jv_8ec30 << 3) | 0xA481;
          (void)jv_8ec30; }
    }
    unsigned prev = to_gray(0);
    if ((((opq_82bf * opq_82bf + opq_82bf) % 2) == 0)) { opq_82bf_b ^= 0; }
    for (unsigned i = 0; i < 1024; i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        if ((((opq_82bf * opq_82bf) % 4) == 2)) {
            { int jv_8a237 = opq_82bf ^ 0x832F;
                jv_8a237 += (jv_8a237 >> 2) + 0xB7;
                jv_8a237 = (jv_8a237 * 0x8) % 0x7FFFFFFF;
                jv_8a237 ^= (jv_8a237 << 3) | 0xC06C;
              (void)jv_8a237; }
        }
        unsigned d = g ^ prev;
        while (d) { transitions += d & 1u; d >>= 1; }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    if ((((opq_82bf * opq_82bf) % 4) == 2)) {
        { int jv_83ed1 = opq_82bf ^ 0x92DB;
            jv_83ed1 = (jv_83ed1 * 0x9) % 0x7FFFFFFF;
            jv_83ed1 ^= (jv_83ed1 << 3) | 0xB06F;
          (void)jv_83ed1; }
    }
    return 0;
}
