#include <stdio.h>
static volatile int opq_d71a = 7;
static volatile int opq_d71a_b = 3;

#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / 32] |= 1u << (i % 32); }
static void clr_bit(int i) { set[i / 32] &= ~(1u << (i % 32)); }
static int get_bit(int i) { return (set[i / 32] >> (i % 32)) & 1u; }
int main(void) {
    if ((((opq_d71a * opq_d71a + opq_d71a_b * opq_d71a_b) % 4) == 3)) {
        { int jv_319f5 = opq_d71a ^ 0xE976;
            jv_319f5 += (jv_319f5 >> 2) + 0x3;
          (void)jv_319f5; }
    }
    for (int i = 0; i < 256; i++) if (i % 3 == 0) set_bit(i);
    if ((((opq_d71a * opq_d71a + opq_d71a_b * opq_d71a_b) % 4) == 3)) {
        { int jv_3269d = opq_d71a ^ 0x73CE;
            jv_3269d += (jv_3269d >> 2) + 0xA7;
            jv_3269d = (jv_3269d * 0x18) % 0x7FFFFFFF;
          (void)jv_3269d; }
    }
    for (int i = 0; i < 256; i++) if (i % 7 == 0) clr_bit(i);
    if ((((opq_d71a * opq_d71a) % 4) == 2)) {
        { int jv_84785 = opq_d71a ^ 0xE13E;
            jv_84785 = (jv_84785 * 0x3A) % 0x7FFFFFFF;
            jv_84785 += (jv_84785 >> 2) + 0xF;
          (void)jv_84785; }
    }
    int count = 0;
    if ((((opq_d71a * opq_d71a + opq_d71a_b * opq_d71a_b) % 4) == 3)) {
        { int jv_79de4 = opq_d71a ^ 0x41BD;
            jv_79de4 = (jv_79de4 * 0x21) % 0x7FFFFFFF;
          (void)jv_79de4; }
    }
    for (int i = 0; i < 256; i++) count += get_bit(i);
    unsigned fold = 0;
    for (int w = 0; w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return 0;
}
