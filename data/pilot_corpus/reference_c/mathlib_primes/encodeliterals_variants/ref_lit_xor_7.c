#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0xF0FBF87 ^ 0xF0FBF87); i < LIM; i++) sieve[i] = (0x7EB3BCAA ^ 0x7EB3BCAB);
    sieve[(0x7DBB8E5 ^ 0x7DBB8E5)] = sieve[(0x349F08C9 ^ 0x349F08C8)] = (0x499444AF ^ 0x499444AF);
    for (int i = (0x63F176E1 ^ 0x63F176E3); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0x74C72438 ^ 0x74C72438);
    int count = (0x1587858D ^ 0x1587858D), last = (0x3D5307D3 ^ 0x3D5307D3);
    for (int i = (0x675F43AE ^ 0x675F43AE); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0xC2DFA00 ^ 0xC2DFA00);
}
