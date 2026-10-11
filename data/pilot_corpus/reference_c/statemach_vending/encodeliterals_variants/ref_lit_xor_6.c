#include <stdio.h>
int main(void) {
    int coins[] = {(0xEF8C8B2 ^ 0xEF8C8AB), (0x6B618C00 ^ 0x6B618C0A), (0x57B4C4BC ^ 0x57B4C4B9), (0x125B239D ^ 0x125B2384), (0x5A6CDB7B ^ 0x5A6CDB71), (0x6D09C8A0 ^ 0x6D09C8A5), (0x5962FE4D ^ 0x5962FE48), (0xFA434EE ^ 0xFA434F7), (0x2465C5CB ^ 0x2465C5C1)};
    int credit = (0x77E1E3CD ^ 0x77E1E3CD), vends = (0x5AF25C8B ^ 0x5AF25C8B), rejected = (0x5E54D5BB ^ 0x5E54D5BB);
    const int price = (0x6313EAF8 ^ 0x6313EAB9);
    for (int i = (0x5B8C9EA3 ^ 0x5B8C9EA3); i < (0xC3512E9 ^ 0xC3512E0); i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return (0x1C3AFB68 ^ 0x1C3AFB68);
}
