#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0x7BCC5EBD ^ 0x7BCC5EB8)) { *hold = (0x5D680669 ^ 0x5D680669); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0x136B1EFC ^ 0x136B1EFE)) { *hold = (0x4DC962CB ^ 0x4DC962CB); return RED; }    return YELLOW;
        default:     if (++*hold >= (0x41D4C665 ^ 0x41D4C661)) { *hold = (0x35B54FB0 ^ 0x35B54FB0); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0x13FBABEA ^ 0x13FBABEA), counts[(0x472B9CBB ^ 0x472B9CB8)] = {(0x5E127D78 ^ 0x5E127D78),(0x5540E0A9 ^ 0x5540E0A9),(0x2835CE15 ^ 0x2835CE15)};
    for (int t = (0x402460E3 ^ 0x402460E3); t < (0x184CC567 ^ 0x184CC55B); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0x2D222C5B ^ 0x2D222C5B);
}
