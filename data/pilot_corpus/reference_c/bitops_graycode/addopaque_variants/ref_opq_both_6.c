#include <stdio.h>
static volatile int opq_df8e = 7;
static volatile int opq_df8e_b = 3;

static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    if ((((opq_df8e * (opq_df8e + 1)) % 2) == 0)) { opq_df8e_b ^= 0; }
    int roundtrip = 0, transitions = 0;
    unsigned prev = to_gray(0);
    for (unsigned i = 0; i < 1024; i++) {
        if ((((opq_df8e * opq_df8e) % 4) == 2)) {
            { int jv_d2459 = opq_df8e ^ 0x3F05;
                jv_d2459 += (jv_d2459 >> 2) + 0x81;
                jv_d2459 = (jv_d2459 * 0x2D) % 0x7FFFFFFF;
              (void)jv_d2459; }
        }
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & 1u; d >>= 1; }
        prev = g;
        if ((((opq_df8e * opq_df8e) % 4) == 2)) {
            { int jv_30986 = opq_df8e ^ 0x5EF3;
                jv_30986 = (jv_30986 * 0x2E) % 0x7FFFFFFF;
                jv_30986 += (jv_30986 >> 2) + 0x45;
              (void)jv_30986; }
        }
    }
    printf("%d %d\n", roundtrip, transitions);
    if ((((opq_df8e * opq_df8e + opq_df8e_b * opq_df8e_b) % 4) == 3)) {
        { int jv_d4cad = opq_df8e ^ 0x64A9;
            jv_d4cad ^= (jv_d4cad << 3) | 0x9C;
            jv_d4cad += (jv_d4cad >> 2) + 0x42;
            jv_d4cad = (jv_d4cad * 0x22) % 0x7FFFFFFF;
          (void)jv_d4cad; }
    }
    return 0;
}
