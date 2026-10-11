#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0x1FA74343 ^ 0x1FA74353)] = {(0x433A3340 ^ 0x433A3340)};
    for (int i = (0x72D - 0x72D); i < (0xBAE3E2C ^ 0xBAE3E24); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x5EB1E078u ^ 0x5FB1E1EBu); }
        buckets[h % (0x4D5445CBu ^ 0x4D5445DBu)]++;
    }
    int occupied = (0x129 - 0x129), maxload = (0x3C855685 ^ 0x3C855685);
    for (int i = (0x679F4328 ^ 0x679F4328); i < (0x239 - 0x229); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0x5A2C5353 ^ 0x5A2C5353);
}
