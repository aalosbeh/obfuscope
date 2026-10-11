#include <stdio.h>
#define WORDS 8
static unsigned nqmhhjpqqzjnqtlzmgjomu[WORDS];
static void set_bit(int i) { nqmhhjpqqzjnqtlzmgjomu[i / 32] |= 1u << (i % 32); }
static void clr_bit(int i) { nqmhhjpqqzjnqtlzmgjomu[i / 32] &= ~(1u << (i % 32)); }
static int get_bit(int i) { return (nqmhhjpqqzjnqtlzmgjomu[i / 32] >> (i % 32)) & 1u; }
int main(void) {
    for (int i = 0; i < 256; i++) if (i % 3 == 0) set_bit(i);
    for (int i = 0; i < 256; i++) if (i % 7 == 0) clr_bit(i);
    int djwblnnemzjklpjnxueq = 0;
    for (int i = 0; i < 256; i++) djwblnnemzjklpjnxueq += get_bit(i);
    unsigned lcrpzvbmocjphirvtu = 0;
    for (int w = 0; w < WORDS; w++) lcrpzvbmocjphirvtu ^= nqmhhjpqqzjnqtlzmgjomu[w];
    printf("%d %08x\n", djwblnnemzjklpjnxueq, lcrpzvbmocjphirvtu);
    return 0;
}
