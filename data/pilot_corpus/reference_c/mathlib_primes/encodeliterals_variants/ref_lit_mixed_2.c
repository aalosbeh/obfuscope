#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0x18AF3B19 ^ 0x18AF3B19); i < LIM; i++) sieve[i] = (0x59181591 ^ 0x59181590);
    sieve[(0x17402082 ^ 0x17402082)] = sieve[(0x5252D893 ^ 0x5252D892)] = (0xDEA - 0xDEA);
    for (int i = (0x9F5 - 0x9F3); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0x670F3A38 ^ 0x670F3A38);
    int count = (0x1F01949B ^ 0x1F01949B), last = (0xB96 - 0xB96);
    for (int i = (0x65A593D3 ^ 0x65A593D3); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0x5710DCD2 ^ 0x5710DCD2);
}
