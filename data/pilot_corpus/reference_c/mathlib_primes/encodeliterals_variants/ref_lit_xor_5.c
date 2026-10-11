#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0x4541B6AE ^ 0x4541B6AE); i < LIM; i++) sieve[i] = (0x7C4B3039 ^ 0x7C4B3038);
    sieve[(0x407D7B67 ^ 0x407D7B67)] = sieve[(0x4ACB8CD0 ^ 0x4ACB8CD1)] = (0x657003BF ^ 0x657003BF);
    for (int i = (0x23A8BFED ^ 0x23A8BFEF); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0x72CFFD59 ^ 0x72CFFD59);
    int count = (0x3CBEC46B ^ 0x3CBEC46B), last = (0x261B5650 ^ 0x261B5650);
    for (int i = (0x51CFC896 ^ 0x51CFC896); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0x5EBEBCC4 ^ 0x5EBEBCC4);
}
