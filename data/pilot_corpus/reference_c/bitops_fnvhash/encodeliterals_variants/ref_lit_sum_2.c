#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0x55B - 0x54B)] = {(0xF71 - 0xF71)};
    for (int i = (0xDF - 0xDF); i < (0x652 - 0x64A); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x1000722u - 0x58Fu); }
        buckets[h % (0xD7Du - 0xD6Du)]++;
    }
    int occupied = (0x87B - 0x87B), maxload = (0x75D - 0x75D);
    for (int i = (0xA02 - 0xA02); i < (0x75 - 0x65); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0xBB - 0xBB);
}
