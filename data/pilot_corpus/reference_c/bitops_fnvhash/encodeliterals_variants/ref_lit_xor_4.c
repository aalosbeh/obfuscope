#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0x3B3EE0D8 ^ 0x3B3EE0C8)] = {(0x63A287FD ^ 0x63A287FD)};
    for (int i = (0xD756486 ^ 0xD756486); i < (0x57E159AC ^ 0x57E159A4); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x4DB549CCu ^ 0x4CB5485Fu); }
        buckets[h % (0x37A5F0D7u ^ 0x37A5F0C7u)]++;
    }
    int occupied = (0x18E8B5AD ^ 0x18E8B5AD), maxload = (0x7F9377B3 ^ 0x7F9377B3);
    for (int i = (0x7A1DF29E ^ 0x7A1DF29E); i < (0x5E4250CD ^ 0x5E4250DD); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0x49054F1A ^ 0x49054F1A);
}
