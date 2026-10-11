#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0x7FA22180 ^ 0x7FA22190)] = {(0x693 - 0x693)};
    for (int i = (0x1F889BE8 ^ 0x1F889BE8); i < (0xA7 - 0x9F); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x100101Bu - 0xE88u); }
        buckets[h % (0x6121EFECu ^ 0x6121EFFCu)]++;
    }
    int occupied = (0xAFA - 0xAFA), maxload = (0x164B0193 ^ 0x164B0193);
    for (int i = (0x237 - 0x237); i < (0x70C457D5 ^ 0x70C457C5); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0xF38F0AB ^ 0xF38F0AB);
}
