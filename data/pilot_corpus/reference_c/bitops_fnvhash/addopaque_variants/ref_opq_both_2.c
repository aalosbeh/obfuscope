#include <stdio.h>
static volatile int opq_a9f0 = 7;
static volatile int opq_a9f0_b = 3;

int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    if ((((opq_a9f0 * opq_a9f0) % 4) == 2)) {
        { int jv_45d7f = opq_a9f0 ^ 0x43C9;
            jv_45d7f += (jv_45d7f >> 2) + 0x6;
            jv_45d7f = (jv_45d7f * 0x8) % 0x7FFFFFFF;
          (void)jv_45d7f; }
    }
    unsigned buckets[16] = {0};
    if (((opq_a9f0 * opq_a9f0 - opq_a9f0) % 2 == 0)) { opq_a9f0_b ^= 0; }
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        buckets[h % 16u]++;
        if ((((opq_a9f0 * opq_a9f0) % 4) == 2)) {
            { int jv_4b21a = opq_a9f0 ^ 0x5F7B;
                jv_4b21a += (jv_4b21a >> 2) + 0x37;
                jv_4b21a ^= (jv_4b21a << 3) | 0x6197;
              (void)jv_4b21a; }
        }
    }
    int occupied = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    if ((((opq_a9f0 * (opq_a9f0 + 1)) % 2) == 0)) { opq_a9f0_b ^= 0; }
    return 0;
}
