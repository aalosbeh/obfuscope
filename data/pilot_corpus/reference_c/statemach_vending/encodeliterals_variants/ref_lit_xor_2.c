#include <stdio.h>
int main(void) {
    int coins[] = {(0x5F366C63 ^ 0x5F366C7A), (0x13D0EE4C ^ 0x13D0EE46), (0x749B1C08 ^ 0x749B1C0D), (0x10C3167B ^ 0x10C31662), (0x110C14D6 ^ 0x110C14DC), (0x60435FCD ^ 0x60435FC8), (0x13A0D6E2 ^ 0x13A0D6E7), (0x228609 ^ 0x228610), (0x60793B8E ^ 0x60793B84)};
    int credit = (0x47D0A53F ^ 0x47D0A53F), vends = (0x2ED34011 ^ 0x2ED34011), rejected = (0xC2BA4F2 ^ 0xC2BA4F2);
    const int price = (0x4F287AEF ^ 0x4F287AAE);
    for (int i = (0xCE2942F ^ 0xCE2942F); i < (0x3AC8D3E1 ^ 0x3AC8D3E8); i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return (0x67910590 ^ 0x67910590);
}
