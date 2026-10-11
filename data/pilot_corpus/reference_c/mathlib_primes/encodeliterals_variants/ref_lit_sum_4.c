#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0x872 - 0x872); i < LIM; i++) sieve[i] = (0x2DC - 0x2DB);
    sieve[(0xDAC - 0xDAC)] = sieve[(0xBC0 - 0xBBF)] = (0xE16 - 0xE16);
    for (int i = (0x42C - 0x42A); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0xEE2 - 0xEE2);
    int count = (0x995 - 0x995), last = (0xA05 - 0xA05);
    for (int i = (0x699 - 0x699); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0xE00 - 0xE00);
}
