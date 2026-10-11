#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0x60DFC387 ^ 0x60DFC387); i < LIM; i++) sieve[i] = (0x2D9203FA ^ 0x2D9203FB);
    sieve[(0x1F43AB2A ^ 0x1F43AB2A)] = sieve[(0x1C30A734 ^ 0x1C30A735)] = (0x198DA88B ^ 0x198DA88B);
    for (int i = (0x124FF332 ^ 0x124FF330); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0x3ED1B301 ^ 0x3ED1B301);
    int count = (0x3D248970 ^ 0x3D248970), last = (0x25D14403 ^ 0x25D14403);
    for (int i = (0x508B19AB ^ 0x508B19AB); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0x1BBCDEB5 ^ 0x1BBCDEB5);
}
