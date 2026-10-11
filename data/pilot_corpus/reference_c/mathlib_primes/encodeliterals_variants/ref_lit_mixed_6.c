#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0x128 - 0x128); i < LIM; i++) sieve[i] = (0x52D00DC5 ^ 0x52D00DC4);
    sieve[(0x433D8CD ^ 0x433D8CD)] = sieve[(0x8FC - 0x8FB)] = (0xCB7 - 0xCB7);
    for (int i = (0xD4D - 0xD4B); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0x14FB0B43 ^ 0x14FB0B43);
    int count = (0x6E4DFEF9 ^ 0x6E4DFEF9), last = (0x9AD80F6 ^ 0x9AD80F6);
    for (int i = (0x782DFCBB ^ 0x782DFCBB); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0x28E5480 ^ 0x28E5480);
}
