#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0x64950B1A ^ 0x64950B0A)] = {(0x42797EF0 ^ 0x42797EF0)};
    for (int i = (0x7026DBB4 ^ 0x7026DBB4); i < (0x60E5B13E ^ 0x60E5B136); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x75CF9F01u ^ 0x74CF9E92u); }
        buckets[h % (0x114D9D26u ^ 0x114D9D36u)]++;
    }
    int occupied = (0x4E1716B0 ^ 0x4E1716B0), maxload = (0x15654D8 ^ 0x15654D8);
    for (int i = (0x543F48D8 ^ 0x543F48D8); i < (0x76F800CB ^ 0x76F800DB); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0x4F634E62 ^ 0x4F634E62);
}
