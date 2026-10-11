#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0xF38 - 0xF28)] = {(0xF0F6F33 ^ 0xF0F6F33)};
    for (int i = (0xB6ED6FA ^ 0xB6ED6FA); i < (0xFCDF84 ^ 0xFCDF8C); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x100059Bu - 0x408u); }
        buckets[h % (0x7692DC22u ^ 0x7692DC32u)]++;
    }
    int occupied = (0x74261E7C ^ 0x74261E7C), maxload = (0x6F245C9C ^ 0x6F245C9C);
    for (int i = (0x122ED946 ^ 0x122ED946); i < (0x724 - 0x714); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0x7EE - 0x7EE);
}
