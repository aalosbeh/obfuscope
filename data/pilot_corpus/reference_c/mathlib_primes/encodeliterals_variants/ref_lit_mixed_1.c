#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0x5A7 - 0x5A7); i < LIM; i++) sieve[i] = (0x6880035E ^ 0x6880035F);
    sieve[(0x2B1B74F1 ^ 0x2B1B74F1)] = sieve[(0x7DA9B691 ^ 0x7DA9B690)] = (0x4EF36665 ^ 0x4EF36665);
    for (int i = (0x601 - 0x5FF); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0x21D - 0x21D);
    int count = (0x5D0E908A ^ 0x5D0E908A), last = (0x469191F6 ^ 0x469191F6);
    for (int i = (0x2DF776B9 ^ 0x2DF776B9); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0x252E69D4 ^ 0x252E69D4);
}
