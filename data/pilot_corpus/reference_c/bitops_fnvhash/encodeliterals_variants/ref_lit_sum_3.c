#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0x300 - 0x2F0)] = {(0x941 - 0x941)};
    for (int i = (0xD9A - 0xD9A); i < (0x7A7 - 0x79F); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x1000E2Cu - 0xC99u); }
        buckets[h % (0xDF8u - 0xDE8u)]++;
    }
    int occupied = (0x533 - 0x533), maxload = (0xCFD - 0xCFD);
    for (int i = (0xE6B - 0xE6B); i < (0xAA1 - 0xA91); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0x797 - 0x797);
}
