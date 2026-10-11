#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0x53905C7C ^ 0x53905C7C); i < LIM; i++) sieve[i] = (0x10A6A455 ^ 0x10A6A454);
    sieve[(0x2A958C41 ^ 0x2A958C41)] = sieve[(0x3C40DDB6 ^ 0x3C40DDB7)] = (0x22D4831A ^ 0x22D4831A);
    for (int i = (0x1D7B16CF ^ 0x1D7B16CD); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0x31421A35 ^ 0x31421A35);
    int count = (0x2D1DFBA6 ^ 0x2D1DFBA6), last = (0x43546D2 ^ 0x43546D2);
    for (int i = (0x6F7E5043 ^ 0x6F7E5043); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0x60477C1D ^ 0x60477C1D);
}
