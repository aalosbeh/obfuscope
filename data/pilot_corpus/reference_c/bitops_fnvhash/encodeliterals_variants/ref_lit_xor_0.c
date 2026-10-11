#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0x46DC586C ^ 0x46DC587C)] = {(0x7D6FE381 ^ 0x7D6FE381)};
    for (int i = (0x6670040F ^ 0x6670040F); i < (0x32087860 ^ 0x32087868); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x39812BC1u ^ 0x38812A52u); }
        buckets[h % (0x36B3F920u ^ 0x36B3F930u)]++;
    }
    int occupied = (0x4479A2FE ^ 0x4479A2FE), maxload = (0x103291E6 ^ 0x103291E6);
    for (int i = (0x33A62CC6 ^ 0x33A62CC6); i < (0x7DFC720D ^ 0x7DFC721D); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0x35760B94 ^ 0x35760B94);
}
