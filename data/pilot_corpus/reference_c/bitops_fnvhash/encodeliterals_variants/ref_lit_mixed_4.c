#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0x6BE - 0x6AE)] = {(0xD4A - 0xD4A)};
    for (int i = (0xE4A - 0xE4A); i < (0x491E8BAC ^ 0x491E8BA4); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x10010F1u - 0xF5Eu); }
        buckets[h % (0xA81C06Cu ^ 0xA81C07Cu)]++;
    }
    int occupied = (0xBA0 - 0xBA0), maxload = (0x1C4 - 0x1C4);
    for (int i = (0xF22 - 0xF22); i < (0x43A - 0x42A); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0x2D2D727 ^ 0x2D2D727);
}
