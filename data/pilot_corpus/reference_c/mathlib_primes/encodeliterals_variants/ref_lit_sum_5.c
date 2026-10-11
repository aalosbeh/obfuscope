#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0x24F - 0x24F); i < LIM; i++) sieve[i] = (0xDE - 0xDD);
    sieve[(0x8AF - 0x8AF)] = sieve[(0xC21 - 0xC20)] = (0xE07 - 0xE07);
    for (int i = (0x827 - 0x825); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0x1BB - 0x1BB);
    int count = (0x7B0 - 0x7B0), last = (0xE65 - 0xE65);
    for (int i = (0x440 - 0x440); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0x494 - 0x494);
}
