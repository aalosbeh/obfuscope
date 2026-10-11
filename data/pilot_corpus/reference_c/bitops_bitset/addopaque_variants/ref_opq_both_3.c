#include <stdio.h>
static volatile int opq_291b = 7;
static volatile int opq_291b_b = 3;

#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / 32] |= 1u << (i % 32); }
static void clr_bit(int i) { set[i / 32] &= ~(1u << (i % 32)); }
static int get_bit(int i) { return (set[i / 32] >> (i % 32)) & 1u; }
int main(void) {
    if ((((opq_291b * opq_291b + opq_291b_b * opq_291b_b) % 4) == 3)) {
        { int jv_6c3cb = opq_291b ^ 0xAE3F;
            jv_6c3cb = (jv_6c3cb * 0x13) % 0x7FFFFFFF;
            jv_6c3cb ^= (jv_6c3cb << 3) | 0x1945;
            jv_6c3cb += (jv_6c3cb >> 2) + 0x4C;
          (void)jv_6c3cb; }
    }
    for (int i = 0; i < 256; i++) if (i % 3 == 0) set_bit(i);
    for (int i = 0; i < 256; i++) if (i % 7 == 0) clr_bit(i);
    if ((((opq_291b * opq_291b + opq_291b_b * opq_291b_b) % 4) == 3)) {
        { int jv_7501d = opq_291b ^ 0x9467;
            jv_7501d += (jv_7501d >> 2) + 0x4D;
            jv_7501d = (jv_7501d * 0x21) % 0x7FFFFFFF;
            jv_7501d ^= (jv_7501d << 3) | 0xBD47;
          (void)jv_7501d; }
    }
    int count = 0;
    for (int i = 0; i < 256; i++) count += get_bit(i);
    if (((opq_291b * opq_291b - opq_291b) % 2 == 0)) { opq_291b_b ^= 0; }
    unsigned fold = 0;
    if ((((opq_291b * opq_291b) % 4) == 2)) {
        { int jv_e10ac = opq_291b ^ 0xFF6E;
            jv_e10ac += (jv_e10ac >> 2) + 0x90;
            jv_e10ac = (jv_e10ac * 0x12) % 0x7FFFFFFF;
          (void)jv_e10ac; }
    }
    for (int w = 0; w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return 0;
}
