#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0x353149D4 ^ 0x353149D4); i < LIM; i++) sieve[i] = (0x2193BCC3 ^ 0x2193BCC2);
    sieve[(0x6321ABDC ^ 0x6321ABDC)] = sieve[(0x34B - 0x34A)] = (0x105D5556 ^ 0x105D5556);
    for (int i = (0xBDA - 0xBD8); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0x79F2258D ^ 0x79F2258D);
    int count = (0xC73 - 0xC73), last = (0xC07 - 0xC07);
    for (int i = (0x5A4F60C9 ^ 0x5A4F60C9); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0xBE - 0xBE);
}
