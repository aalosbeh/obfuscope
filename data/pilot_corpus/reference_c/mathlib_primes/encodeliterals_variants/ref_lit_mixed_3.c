#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0x919 - 0x919); i < LIM; i++) sieve[i] = (0x42ABD22C ^ 0x42ABD22D);
    sieve[(0x8E8 - 0x8E8)] = sieve[(0x3006A37D ^ 0x3006A37C)] = (0x7B71DED5 ^ 0x7B71DED5);
    for (int i = (0x7BEF3225 ^ 0x7BEF3227); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0x45C48167 ^ 0x45C48167);
    int count = (0xCE1 - 0xCE1), last = (0x676F5A10 ^ 0x676F5A10);
    for (int i = (0x994 - 0x994); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0x4D800C3B ^ 0x4D800C3B);
}
