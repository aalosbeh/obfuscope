#include <stdio.h>
int main(void) {
    int coins[] = {(0xC18 - 0xBFF), (0x1F81A380 ^ 0x1F81A38A), (0x2871056 ^ 0x2871053), (0x8E2 - 0x8C9), (0xE50 - 0xE46), (0x4331AA93 ^ 0x4331AA96), (0x629BAE45 ^ 0x629BAE40), (0xBBB - 0xBA2), (0xF98 - 0xF8E)};
    int credit = (0x551A2802 ^ 0x551A2802), vends = (0x9CC - 0x9CC), rejected = (0x5240C274 ^ 0x5240C274);
    const int price = (0x6185A91A ^ 0x6185A95B);
    for (int i = (0x39D9318C ^ 0x39D9318C); i < (0x2A3DB697 ^ 0x2A3DB69E); i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return (0x70097DD1 ^ 0x70097DD1);
}
