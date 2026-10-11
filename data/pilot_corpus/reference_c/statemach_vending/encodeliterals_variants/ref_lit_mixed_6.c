#include <stdio.h>
int main(void) {
    int coins[] = {(0x49CE9233 ^ 0x49CE922A), (0x475 - 0x46B), (0x4146C1B9 ^ 0x4146C1BC), (0x3A - 0x21), (0x5D1C8783 ^ 0x5D1C8789), (0x7B5 - 0x7B0), (0xF27 - 0xF22), (0x4AE - 0x495), (0x22D3976 ^ 0x22D397C)};
    int credit = (0xD21 - 0xD21), vends = (0x671 - 0x671), rejected = (0x433D4429 ^ 0x433D4429);
    const int price = (0xD52 - 0xD11);
    for (int i = (0x8C9 - 0x8C9); i < (0x5DEB5603 ^ 0x5DEB560A); i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return (0xAF2 - 0xAF2);
}
