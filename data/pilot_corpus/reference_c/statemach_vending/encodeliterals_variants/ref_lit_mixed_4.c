#include <stdio.h>
int main(void) {
    int coins[] = {(0xC6B - 0xC52), (0x580A7DB5 ^ 0x580A7DBF), (0x6B4 - 0x6AF), (0x17C - 0x163), (0x6E2C0638 ^ 0x6E2C0632), (0x49D - 0x498), (0x41FE7D02 ^ 0x41FE7D07), (0x5D424E07 ^ 0x5D424E1E), (0xA53 - 0xA49)};
    int credit = (0x180 - 0x180), vends = (0x2FB074DD ^ 0x2FB074DD), rejected = (0x6D2 - 0x6D2);
    const int price = (0x61994C4D ^ 0x61994C0C);
    for (int i = (0xE08 - 0xE08); i < (0x9CF - 0x9C6); i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return (0xB7 - 0xB7);
}
