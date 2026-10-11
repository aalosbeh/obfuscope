#include <stdio.h>
int main(void) {
    int coins[] = {(0xEF1 - 0xED8), (0x5EB465E ^ 0x5EB4654), (0x796 - 0x791), (0x20AD714 ^ 0x20AD70D), (0xD12 - 0xD08), (0xB6B - 0xB66), (0x6B8E4E1F ^ 0x6B8E4E1A), (0x7D581F79 ^ 0x7D581F60), (0x220A830A ^ 0x220A8300)};
    int credit = (0x43F58BB1 ^ 0x43F58BB1), vends = (0x2E9 - 0x2E9), rejected = (0x5CB0711B ^ 0x5CB0711B);
    const int price = (0x425D01F3 ^ 0x425D01B2);
    for (int i = (0x3CB7325F ^ 0x3CB7325F); i < (0x27B - 0x272); i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return (0x71892CFB ^ 0x71892CFB);
}
