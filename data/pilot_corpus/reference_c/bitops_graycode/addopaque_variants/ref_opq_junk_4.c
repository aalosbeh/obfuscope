#include <stdio.h>
static volatile int opq_e3bf = 7;
static volatile int opq_e3bf_b = 3;

static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    int roundtrip = 0, transitions = 0;
    unsigned prev = to_gray(0);
    for (unsigned i = 0; i < 1024; i++) {
        if ((((opq_e3bf * opq_e3bf) % 4) == 2)) {
            { int jv_15b7f = opq_e3bf ^ 0xF6E7;
                jv_15b7f ^= (jv_15b7f << 3) | 0x44B6;
                jv_15b7f = (jv_15b7f * 0x3A) % 0x7FFFFFFF;
              (void)jv_15b7f; }
        }
        unsigned g = to_gray(i);
        if ((((opq_e3bf * opq_e3bf + opq_e3bf_b * opq_e3bf_b) % 4) == 3)) {
            { int jv_a5469 = opq_e3bf ^ 0xB95E;
                jv_a5469 = (jv_a5469 * 0x29) % 0x7FFFFFFF;
                jv_a5469 += (jv_a5469 >> 2) + 0xD2;
                jv_a5469 ^= (jv_a5469 << 3) | 0x31DA;
              (void)jv_a5469; }
        }
        if (from_gray(g) == i) roundtrip++;
        if ((((opq_e3bf * opq_e3bf) % 4) == 2)) {
            { int jv_12283 = opq_e3bf ^ 0x3BCF;
                jv_12283 = (jv_12283 * 0x22) % 0x7FFFFFFF;
              (void)jv_12283; }
        }
        unsigned d = g ^ prev;
        while (d) { transitions += d & 1u; d >>= 1; }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    if ((((opq_e3bf * opq_e3bf + opq_e3bf_b * opq_e3bf_b) % 4) == 3)) {
        { int jv_9abbb = opq_e3bf ^ 0x693A;
            jv_9abbb ^= (jv_9abbb << 3) | 0x8727;
          (void)jv_9abbb; }
    }
    return 0;
}
