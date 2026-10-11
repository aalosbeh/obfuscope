#include <stdio.h>
#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / (0x2E77B9C4 ^ 0x2E77B9E4)] |= (0x6700FD18u ^ 0x6700FD19u) << (i % (0x7CB77CE3 ^ 0x7CB77CC3)); }
static void clr_bit(int i) { set[i / (0x41DA35B8 ^ 0x41DA3598)] &= ~((0x271087ABu ^ 0x271087AAu) << (i % (0x7D1BE5 ^ 0x7D1BC5))); }
static int get_bit(int i) { return (set[i / (0x507325D5 ^ 0x507325F5)] >> (i % (0x46B21E66 ^ 0x46B21E46))) & (0x67AA5F86u ^ 0x67AA5F87u); }
int main(void) {
    for (int i = (0x1B0C7FA9 ^ 0x1B0C7FA9); i < (0x20957BFF ^ 0x20957AFF); i++) if (i % (0x75F919D3 ^ 0x75F919D0) == (0x55549C68 ^ 0x55549C68)) set_bit(i);
    for (int i = (0x2ECFD54 ^ 0x2ECFD54); i < (0x3914C4EA ^ 0x3914C5EA); i++) if (i % (0x784693D9 ^ 0x784693DE) == (0x21B52968 ^ 0x21B52968)) clr_bit(i);
    int count = (0x1EDD61E7 ^ 0x1EDD61E7);
    for (int i = (0x71611A4E ^ 0x71611A4E); i < (0x2E9934BB ^ 0x2E9935BB); i++) count += get_bit(i);
    unsigned fold = (0x235BED10 ^ 0x235BED10);
    for (int w = (0x226E4C76 ^ 0x226E4C76); w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return (0xA82767B ^ 0xA82767B);
}
