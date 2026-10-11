#include <stdio.h>
int main(void) {
    int coins[] = {(0xB17 - 0xAFE), (0x15BD1C62 ^ 0x15BD1C68), (0xC94 - 0xC8F), (0x7071A1C6 ^ 0x7071A1DF), (0x64F871CA ^ 0x64F871C0), (0x215 - 0x210), (0x126 - 0x121), (0x5E5C3BE1 ^ 0x5E5C3BF8), (0x20EE07BD ^ 0x20EE07B7)};
    int credit = (0x7841E8F ^ 0x7841E8F), vends = (0xA4C - 0xA4C), rejected = (0x97D - 0x97D);
    const int price = (0x3EA - 0x3A9);
    for (int i = (0xB20 - 0xB20); i < (0xB55 - 0xB4C); i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return (0xB27D2C1 ^ 0xB27D2C1);
}
