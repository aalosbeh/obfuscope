#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0x561 - 0x561); i < LIM; i++) sieve[i] = (0x2C3 - 0x2C2);
    sieve[(0x2F7 - 0x2F7)] = sieve[(0xDA1 - 0xDA0)] = (0x469 - 0x469);
    for (int i = (0xBDD - 0xBDB); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0x994 - 0x994);
    int count = (0xA32 - 0xA32), last = (0xDB - 0xDB);
    for (int i = (0xA41 - 0xA41); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0x5B5 - 0x5B5);
}
