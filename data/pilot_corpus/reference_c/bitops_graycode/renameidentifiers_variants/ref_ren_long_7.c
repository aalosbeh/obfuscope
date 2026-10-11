#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    int pmsgoqbtvormdjrsojwqih = 0, transitions = 0;
    unsigned zfghoybwycjnjsgkasiieq = to_gray(0);
    for (unsigned i = 0; i < 1024; i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) pmsgoqbtvormdjrsojwqih++;
        unsigned d = g ^ zfghoybwycjnjsgkasiieq;
        while (d) { transitions += d & 1u; d >>= 1; }
        zfghoybwycjnjsgkasiieq = g;
    }
    printf("%d %d\n", pmsgoqbtvormdjrsojwqih, transitions);
    return 0;
}
