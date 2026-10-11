#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0x781 - 0x771)] = {(0x1CD - 0x1CD)};
    for (int i = (0x51F - 0x51F); i < (0xC8A - 0xC82); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x1000F5Eu - 0xDCBu); }
        buckets[h % (0xE37u - 0xE27u)]++;
    }
    int occupied = (0x364 - 0x364), maxload = (0x40C - 0x40C);
    for (int i = (0xD60 - 0xD60); i < (0x327 - 0x317); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0x5FA - 0x5FA);
}
