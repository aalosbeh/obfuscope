#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0xDE8 - 0xDD8)] = {(0xE81 - 0xE81)};
    for (int i = (0xB8C - 0xB8C); i < (0xE14 - 0xE0C); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x1000444u - 0x2B1u); }
        buckets[h % (0xB63u - 0xB53u)]++;
    }
    int occupied = (0x88C - 0x88C), maxload = (0xC30 - 0xC30);
    for (int i = (0xAD6 - 0xAD6); i < (0x985 - 0x975); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0x1EC - 0x1EC);
}
