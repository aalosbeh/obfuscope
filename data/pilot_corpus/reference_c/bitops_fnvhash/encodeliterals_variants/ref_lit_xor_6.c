#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0x2CEBD3D3 ^ 0x2CEBD3C3)] = {(0x1F1170A4 ^ 0x1F1170A4)};
    for (int i = (0x585B27A ^ 0x585B27A); i < (0x34B8D38C ^ 0x34B8D384); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x44B88044u ^ 0x45B881D7u); }
        buckets[h % (0x125964A6u ^ 0x125964B6u)]++;
    }
    int occupied = (0x7110FAFD ^ 0x7110FAFD), maxload = (0x566CEB39 ^ 0x566CEB39);
    for (int i = (0x253E393E ^ 0x253E393E); i < (0x5126ADFD ^ 0x5126ADED); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0x22086AA8 ^ 0x22086AA8);
}
