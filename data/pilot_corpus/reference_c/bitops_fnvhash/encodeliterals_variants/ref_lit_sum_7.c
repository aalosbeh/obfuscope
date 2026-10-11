#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0x586 - 0x576)] = {(0x3C0 - 0x3C0)};
    for (int i = (0xBA1 - 0xBA1); i < (0x1C5 - 0x1BD); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x1000F56u - 0xDC3u); }
        buckets[h % (0xAD2u - 0xAC2u)]++;
    }
    int occupied = (0xE60 - 0xE60), maxload = (0x8DC - 0x8DC);
    for (int i = (0xAEA - 0xAEA); i < (0x9E9 - 0x9D9); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0x93 - 0x93);
}
