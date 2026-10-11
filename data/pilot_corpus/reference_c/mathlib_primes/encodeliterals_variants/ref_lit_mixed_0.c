#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0xCC1 - 0xCC1); i < LIM; i++) sieve[i] = (0x337 - 0x336);
    sieve[(0x69C - 0x69C)] = sieve[(0x671 - 0x670)] = (0x45B9A2B5 ^ 0x45B9A2B5);
    for (int i = (0xE48 - 0xE46); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0x379BBDD5 ^ 0x379BBDD5);
    int count = (0x1314758 ^ 0x1314758), last = (0x578C57C0 ^ 0x578C57C0);
    for (int i = (0x7E0D8E63 ^ 0x7E0D8E63); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0x38EDF8F2 ^ 0x38EDF8F2);
}
