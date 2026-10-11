#include <stdio.h>
int main(void) {
    int coins[] = {(0x345 - 0x32C), (0x592 - 0x588), (0x516 - 0x511), (0x31A - 0x301), (0xC1C - 0xC12), (0x4681D30E ^ 0x4681D30B), (0x1986D597 ^ 0x1986D592), (0xD4A - 0xD31), (0x892 - 0x888)};
    int credit = (0x7F7 - 0x7F7), vends = (0x100 - 0x100), rejected = (0x469 - 0x469);
    const int price = (0x7FF - 0x7BE);
    for (int i = (0xED7B5E3 ^ 0xED7B5E3); i < (0xA09 - 0xA00); i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return (0x76C896C3 ^ 0x76C896C3);
}
