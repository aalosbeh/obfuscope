#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0x7BE - 0x7AE)] = {(0x4B528C90 ^ 0x4B528C90)};
    for (int i = (0x523 - 0x523); i < (0x91B - 0x913); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x1000C89u - 0xAF6u); }
        buckets[h % (0x343u - 0x333u)]++;
    }
    int occupied = (0x4BC0C48C ^ 0x4BC0C48C), maxload = (0x8B3 - 0x8B3);
    for (int i = (0x26A0AEB1 ^ 0x26A0AEB1); i < (0x49A - 0x48A); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0x875 - 0x875);
}
