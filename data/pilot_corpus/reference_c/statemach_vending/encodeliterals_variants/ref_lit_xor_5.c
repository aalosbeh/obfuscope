#include <stdio.h>
int main(void) {
    int coins[] = {(0x3BBEF570 ^ 0x3BBEF569), (0x5E7F7608 ^ 0x5E7F7602), (0x3E6AC9CC ^ 0x3E6AC9C9), (0x153904C0 ^ 0x153904D9), (0x6B2D9480 ^ 0x6B2D948A), (0x2B3A4682 ^ 0x2B3A4687), (0x36B12608 ^ 0x36B1260D), (0x790D4AE0 ^ 0x790D4AF9), (0x1041FE72 ^ 0x1041FE78)};
    int credit = (0x69437744 ^ 0x69437744), vends = (0xCB9E0CD ^ 0xCB9E0CD), rejected = (0x1EE96E08 ^ 0x1EE96E08);
    const int price = (0x1918BC20 ^ 0x1918BC61);
    for (int i = (0x77D0DD1B ^ 0x77D0DD1B); i < (0x2AFA41B2 ^ 0x2AFA41BB); i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return (0x16B63D52 ^ 0x16B63D52);
}
