#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0xC9BD053 ^ 0xC9BD043)] = {(0x3FE - 0x3FE)};
    for (int i = (0x9AF - 0x9AF); i < (0x46F - 0x467); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x1000D65u - 0xBD2u); }
        buckets[h % (0x72C32864u ^ 0x72C32874u)]++;
    }
    int occupied = (0x70B - 0x70B), maxload = (0xA64 - 0xA64);
    for (int i = (0x47FCE1CA ^ 0x47FCE1CA); i < (0xFC5A8B6 ^ 0xFC5A8A6); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0xF3D - 0xF3D);
}
