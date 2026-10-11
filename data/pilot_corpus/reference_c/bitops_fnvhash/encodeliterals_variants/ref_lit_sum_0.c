#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0x298 - 0x288)] = {(0xC0 - 0xC0)};
    for (int i = (0x621 - 0x621); i < (0xF35 - 0xF2D); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x1000DA1u - 0xC0Eu); }
        buckets[h % (0xC3Au - 0xC2Au)]++;
    }
    int occupied = (0xF25 - 0xF25), maxload = (0x7E0 - 0x7E0);
    for (int i = (0xE72 - 0xE72); i < (0x727 - 0x717); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0xA51 - 0xA51);
}
