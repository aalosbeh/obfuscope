#include <stdio.h>
int main(void) {
    int coins[] = {(0x693B7415 ^ 0x693B740C), (0x3F6FA736 ^ 0x3F6FA73C), (0x635C08F7 ^ 0x635C08F2), (0x7A86DB87 ^ 0x7A86DB9E), (0x4C1226F ^ 0x4C12265), (0x42A14F82 ^ 0x42A14F87), (0x75A16C3A ^ 0x75A16C3F), (0xD1EABCC ^ 0xD1EABD5), (0x22C2A95C ^ 0x22C2A956)};
    int credit = (0x1CE50AD9 ^ 0x1CE50AD9), vends = (0xEBC2BC7 ^ 0xEBC2BC7), rejected = (0x5DDD1F5E ^ 0x5DDD1F5E);
    const int price = (0x74EC5F01 ^ 0x74EC5F40);
    for (int i = (0x4A8814E ^ 0x4A8814E); i < (0x56310594 ^ 0x5631059D); i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return (0x5A4D4156 ^ 0x5A4D4156);
}
