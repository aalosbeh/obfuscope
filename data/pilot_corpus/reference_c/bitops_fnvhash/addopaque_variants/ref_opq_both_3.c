#include <stdio.h>
static volatile int opq_ab48 = 7;
static volatile int opq_ab48_b = 3;

int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    if ((((opq_ab48 * opq_ab48) % 4) == 2)) {
        { int jv_740e5 = opq_ab48 ^ 0x8B5F;
            jv_740e5 = (jv_740e5 * 0xE) % 0x7FFFFFFF;
            jv_740e5 += (jv_740e5 >> 2) + 0xBC;
          (void)jv_740e5; }
    }
    unsigned buckets[16] = {0};
    for (int i = 0; i < 8; i++) {
        if ((((opq_ab48 * opq_ab48 + opq_ab48) % 2) == 0)) { opq_ab48_b ^= 0; }
        unsigned h = 2166136261u;
        if ((((opq_ab48 * (opq_ab48 + 1)) % 2) == 0)) { opq_ab48_b ^= 0; }
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        buckets[h % 16u]++;
        if ((((opq_ab48 * (opq_ab48 + 1)) % 2) == 0)) { opq_ab48_b ^= 0; }
    }
    int occupied = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return 0;
}
