#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0xCA0 - 0xC90)] = {(0xBD1 - 0xBD1)};
    for (int i = (0x29D56720 ^ 0x29D56720); i < (0x62958F9E ^ 0x62958F96); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x10006B3u - 0x520u); }
        buckets[h % (0x15982FD9u ^ 0x15982FC9u)]++;
    }
    int occupied = (0x6B4BD466 ^ 0x6B4BD466), maxload = (0xE84 - 0xE84);
    for (int i = (0x4BCEE888 ^ 0x4BCEE888); i < (0xEA7 - 0xE97); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0x1C94D535 ^ 0x1C94D535);
}
