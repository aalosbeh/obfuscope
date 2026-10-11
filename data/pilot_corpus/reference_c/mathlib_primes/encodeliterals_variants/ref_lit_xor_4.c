#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0x4F7D682D ^ 0x4F7D682D); i < LIM; i++) sieve[i] = (0x6940359D ^ 0x6940359C);
    sieve[(0xB1F7860 ^ 0xB1F7860)] = sieve[(0x19AA5C2B ^ 0x19AA5C2A)] = (0x11E52E94 ^ 0x11E52E94);
    for (int i = (0x5FFA0274 ^ 0x5FFA0276); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0x69BC3792 ^ 0x69BC3792);
    int count = (0x5C377B2F ^ 0x5C377B2F), last = (0x44D41ED ^ 0x44D41ED);
    for (int i = (0x29D06337 ^ 0x29D06337); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0x54086E9A ^ 0x54086E9A);
}
