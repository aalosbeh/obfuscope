#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[(0x5B5CF5FA ^ 0x5B5CF5EA)] = {(0xB84A944 ^ 0xB84A944)};
    for (int i = (0x6A772989 ^ 0x6A772989); i < (0x37BB1629 ^ 0x37BB1621); i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= (0x629017B6u ^ 0x63901625u); }
        buckets[h % (0x5ADu - 0x59Du)]++;
    }
    int occupied = (0x86A - 0x86A), maxload = (0x4031ADA2 ^ 0x4031ADA2);
    for (int i = (0x3D - 0x3D); i < (0x33EDA141 ^ 0x33EDA151); i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return (0xA65 - 0xA65);
}
