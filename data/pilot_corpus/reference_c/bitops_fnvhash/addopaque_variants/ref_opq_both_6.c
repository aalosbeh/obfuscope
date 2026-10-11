#include <stdio.h>
static volatile int opq_c842 = 7;
static volatile int opq_c842_b = 3;

int main(void) {
    if ((((opq_c842 * (opq_c842 + 1)) % 2) == 0)) { opq_c842_b ^= 0; }
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    if ((((opq_c842 * (opq_c842 + 1)) % 2) == 0)) { opq_c842_b ^= 0; }
    unsigned buckets[16] = {0};
    if ((((opq_c842 * opq_c842 + opq_c842_b * opq_c842_b) % 4) == 3)) {
        { int jv_19c72 = opq_c842 ^ 0x95C8;
            jv_19c72 ^= (jv_19c72 << 3) | 0x351F;
          (void)jv_19c72; }
    }
    for (int i = 0; i < 8; i++) {
        if ((((opq_c842 * opq_c842 + opq_c842) % 2) == 0)) { opq_c842_b ^= 0; }
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        buckets[h % 16u]++;
    }
    int occupied = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return 0;
}
