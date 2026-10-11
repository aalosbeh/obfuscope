#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0x2A9 - 0x299)] = {(0x908 - 0x908)};
    for (int i = (0x718 - 0x718); i < (0xC93 - 0xC8B); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x100041Fu - 0x28Cu); }
        buckets[h % (0x55u - 0x45u)]++;
    }
    int occupied = (0xF92 - 0xF92), maxload = (0xC70 - 0xC70);
    for (int i = (0xC9C - 0xC9C); i < (0x532 - 0x522); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0x904 - 0x904);
}
