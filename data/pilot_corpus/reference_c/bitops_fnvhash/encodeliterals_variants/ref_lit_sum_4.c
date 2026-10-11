#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0x385 - 0x375)] = {(0x371 - 0x371)};
    for (int i = (0x4FB - 0x4FB); i < (0x258 - 0x250); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x1000F9Eu - 0xE0Bu); }
        buckets[h % (0x73Eu - 0x72Eu)]++;
    }
    int occupied = (0x5E0 - 0x5E0), maxload = (0xC97 - 0xC97);
    for (int i = (0xED3 - 0xED3); i < (0xE2C - 0xE1C); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0xFD9 - 0xFD9);
}
