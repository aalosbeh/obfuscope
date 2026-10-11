#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0x6BB6B2C9 ^ 0x6BB6B2D9)] = {(0x4C03F7CB ^ 0x4C03F7CB)};
    for (int i = (0x35FE1CE7 ^ 0x35FE1CE7); i < (0x73061494 ^ 0x7306149C); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x5389E84Du ^ 0x5289E9DEu); }
        buckets[h % (0x4CAFA9F5u ^ 0x4CAFA9E5u)]++;
    }
    int occupied = (0x462E2134 ^ 0x462E2134), maxload = (0xDBAEF7F ^ 0xDBAEF7F);
    for (int i = (0x36A3F9A0 ^ 0x36A3F9A0); i < (0x2DFB6DF0 ^ 0x2DFB6DE0); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0x577D077E ^ 0x577D077E);
}
