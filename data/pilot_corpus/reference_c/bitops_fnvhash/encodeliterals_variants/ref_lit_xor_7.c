#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0x6FDF4DA5 ^ 0x6FDF4DB5)] = {(0x4AE62058 ^ 0x4AE62058)};
    for (int i = (0x7BD1DE33 ^ 0x7BD1DE33); i < (0x21B78BEE ^ 0x21B78BE6); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x52FB37Fu ^ 0x42FB2ECu); }
        buckets[h % (0x75636E9Cu ^ 0x75636E8Cu)]++;
    }
    int occupied = (0x3FF45CEC ^ 0x3FF45CEC), maxload = (0x3D9A3767 ^ 0x3D9A3767);
    for (int i = (0x3B560353 ^ 0x3B560353); i < (0x4DC4883E ^ 0x4DC4882E); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0x5A75ED9D ^ 0x5A75ED9D);
}
