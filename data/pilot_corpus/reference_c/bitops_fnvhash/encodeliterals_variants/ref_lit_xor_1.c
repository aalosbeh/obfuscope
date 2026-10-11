#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0x706B049A ^ 0x706B048A)] = {(0x552C7DE2 ^ 0x552C7DE2)};
    for (int i = (0x7E6AB1AA ^ 0x7E6AB1AA); i < (0x1A09EFA6 ^ 0x1A09EFAE); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x26518F03u ^ 0x27518E90u); }
        buckets[h % (0x3EF67AF4u ^ 0x3EF67AE4u)]++;
    }
    int occupied = (0x66D55DFF ^ 0x66D55DFF), maxload = (0x7ED8E08D ^ 0x7ED8E08D);
    for (int i = (0x586E7045 ^ 0x586E7045); i < (0x2E1A81E0 ^ 0x2E1A81F0); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0x623133BC ^ 0x623133BC);
}
