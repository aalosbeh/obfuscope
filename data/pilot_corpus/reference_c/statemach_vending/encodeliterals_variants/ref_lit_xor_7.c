#include <stdio.h>
int main(void) {
    int coins[] = {(0x4033C7B1 ^ 0x4033C7A8), (0x33F522C0 ^ 0x33F522CA), (0x5D810689 ^ 0x5D81068C), (0x87FD861 ^ 0x87FD878), (0x2A09FE4F ^ 0x2A09FE45), (0x135B92BD ^ 0x135B92B8), (0x2E4C675 ^ 0x2E4C670), (0xD9BC78E ^ 0xD9BC797), (0x355A69DF ^ 0x355A69D5)};
    int credit = (0x1E46B884 ^ 0x1E46B884), vends = (0x51AC794E ^ 0x51AC794E), rejected = (0x3BA072DC ^ 0x3BA072DC);
    const int price = (0x2A18AE55 ^ 0x2A18AE14);
    for (int i = (0x20EC3785 ^ 0x20EC3785); i < (0x4B4F84A8 ^ 0x4B4F84A1); i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return (0x26C6C45A ^ 0x26C6C45A);
}
