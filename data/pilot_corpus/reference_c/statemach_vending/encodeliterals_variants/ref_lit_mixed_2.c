#include <stdio.h>
int main(void) {
    int coins[] = {(0x67D - 0x664), (0x2F37293B ^ 0x2F372931), (0x503F6010 ^ 0x503F6015), (0x52590AAA ^ 0x52590AB3), (0x358 - 0x34E), (0x414 - 0x40F), (0x82A9A17 ^ 0x82A9A12), (0x418 - 0x3FF), (0x34A30F58 ^ 0x34A30F52)};
    int credit = (0x5E8D353C ^ 0x5E8D353C), vends = (0xB08 - 0xB08), rejected = (0x209D474D ^ 0x209D474D);
    const int price = (0x42F - 0x3EE);
    for (int i = (0x4285DA1D ^ 0x4285DA1D); i < (0x37A07D92 ^ 0x37A07D9B); i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return (0x7528FD87 ^ 0x7528FD87);
}
