#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0x3B121C5F ^ 0x3B121C4F)] = {(0x583F8491 ^ 0x583F8491)};
    for (int i = (0x25BCAA78 ^ 0x25BCAA78); i < (0x519790EB ^ 0x519790E3); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x2DAEDC8Fu ^ 0x2CAEDD1Cu); }
        buckets[h % (0x4FEF8777u ^ 0x4FEF8767u)]++;
    }
    int occupied = (0x1CED8245 ^ 0x1CED8245), maxload = (0x6DAAEC04 ^ 0x6DAAEC04);
    for (int i = (0x7975B426 ^ 0x7975B426); i < (0x64A81846 ^ 0x64A81856); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0x4C15F78D ^ 0x4C15F78D);
}
