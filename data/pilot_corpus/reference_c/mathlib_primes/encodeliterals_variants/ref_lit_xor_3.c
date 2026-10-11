#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0x46B5CA42 ^ 0x46B5CA42); i < LIM; i++) sieve[i] = (0x4F960949 ^ 0x4F960948);
    sieve[(0xB6A2DE4 ^ 0xB6A2DE4)] = sieve[(0x2F1B4D5A ^ 0x2F1B4D5B)] = (0x180E1237 ^ 0x180E1237);
    for (int i = (0x400C1A91 ^ 0x400C1A93); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0x184C32C0 ^ 0x184C32C0);
    int count = (0x3EECEABD ^ 0x3EECEABD), last = (0x3D04CD1D ^ 0x3D04CD1D);
    for (int i = (0x612FB1 ^ 0x612FB1); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0x7050BE0C ^ 0x7050BE0C);
}
