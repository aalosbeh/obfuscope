#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0x7AA79FD6 ^ 0x7AA79FD3)) { *hold = (0x13BBF331 ^ 0x13BBF331); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0x4E47AA18 ^ 0x4E47AA1A)) { *hold = (0x7E3CE389 ^ 0x7E3CE389); return RED; }    return YELLOW;
        default:     if (++*hold >= (0x1229AB7B ^ 0x1229AB7F)) { *hold = (0x4881A3FF ^ 0x4881A3FF); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0x1ADC9636 ^ 0x1ADC9636), counts[(0x6376F82E ^ 0x6376F82D)] = {(0x7BBCEC6F ^ 0x7BBCEC6F),(0x464A0150 ^ 0x464A0150),(0x6B793822 ^ 0x6B793822)};
    for (int t = (0x297E99E1 ^ 0x297E99E1); t < (0x56FA83B4 ^ 0x56FA8388); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0x7054CC1A ^ 0x7054CC1A);
}
