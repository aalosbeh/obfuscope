#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0x3A6A9FE7 ^ 0x3A6A9FE7); i < LIM; i++) sieve[i] = (0x4CA78DEA ^ 0x4CA78DEB);
    sieve[(0x7DC09FF ^ 0x7DC09FF)] = sieve[(0x46A08363 ^ 0x46A08362)] = (0x51A66CB2 ^ 0x51A66CB2);
    for (int i = (0x16BE0A81 ^ 0x16BE0A83); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0x3B16D19B ^ 0x3B16D19B);
    int count = (0x4D1EF023 ^ 0x4D1EF023), last = (0xD82002 ^ 0xD82002);
    for (int i = (0x2624B943 ^ 0x2624B943); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0x30ECCC16 ^ 0x30ECCC16);
}
