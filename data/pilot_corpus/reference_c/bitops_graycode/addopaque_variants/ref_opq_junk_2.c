#include <stdio.h>
static volatile int opq_76ee = 7;
static volatile int opq_76ee_b = 3;

static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    int roundtrip = 0, transitions = 0;
    if ((((opq_76ee * opq_76ee + opq_76ee_b * opq_76ee_b) % 4) == 3)) {
        { int jv_fccee = opq_76ee ^ 0x8B2C;
            jv_fccee += (jv_fccee >> 2) + 0xCC;
          (void)jv_fccee; }
    }
    unsigned prev = to_gray(0);
    for (unsigned i = 0; i < 1024; i++) {
        unsigned g = to_gray(i);
        if ((((opq_76ee * opq_76ee) % 4) == 2)) {
            { int jv_71e8e = opq_76ee ^ 0x7893;
                jv_71e8e = (jv_71e8e * 0xB) % 0x7FFFFFFF;
                jv_71e8e ^= (jv_71e8e << 3) | 0xF9DA;
                jv_71e8e += (jv_71e8e >> 2) + 0xC7;
              (void)jv_71e8e; }
        }
        if (from_gray(g) == i) roundtrip++;
        if ((((opq_76ee * opq_76ee + opq_76ee_b * opq_76ee_b) % 4) == 3)) {
            { int jv_36750 = opq_76ee ^ 0x956C;
                jv_36750 = (jv_36750 * 0x2C) % 0x7FFFFFFF;
              (void)jv_36750; }
        }
        unsigned d = g ^ prev;
        while (d) { transitions += d & 1u; d >>= 1; }
        prev = g;
        if ((((opq_76ee * opq_76ee + opq_76ee_b * opq_76ee_b) % 4) == 3)) {
            { int jv_f1efb = opq_76ee ^ 0xD1FA;
                jv_f1efb += (jv_f1efb >> 2) + 0x87;
                jv_f1efb = (jv_f1efb * 0x11) % 0x7FFFFFFF;
                jv_f1efb ^= (jv_f1efb << 3) | 0xB5CB;
              (void)jv_f1efb; }
        }
    }
    printf("%d %d\n", roundtrip, transitions);
    return 0;
}
