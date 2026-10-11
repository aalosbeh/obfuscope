#include <stdio.h>
static volatile int opq_fab1 = 7;
static volatile int opq_fab1_b = 3;

int main(void) {
    if ((((opq_fab1 * opq_fab1) % 4) == 2)) {
        { int jv_7e347 = opq_fab1 ^ 0xBF07;
            jv_7e347 ^= (jv_7e347 << 3) | 0x38CB;
          (void)jv_7e347; }
    }
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    if ((((opq_fab1 * opq_fab1 + opq_fab1_b * opq_fab1_b) % 4) == 3)) {
        { int jv_db7ca = opq_fab1 ^ 0xB70E;
            jv_db7ca += (jv_db7ca >> 2) + 0x22;
            jv_db7ca ^= (jv_db7ca << 3) | 0x84E9;
            jv_db7ca = (jv_db7ca * 0x16) % 0x7FFFFFFF;
          (void)jv_db7ca; }
    }
    unsigned buckets[16] = {0};
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        if ((((opq_fab1 * opq_fab1 + opq_fab1_b * opq_fab1_b) % 4) == 3)) {
            { int jv_33168 = opq_fab1 ^ 0x30D8;
                jv_33168 ^= (jv_33168 << 3) | 0x2BE;
              (void)jv_33168; }
        }
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        buckets[h % 16u]++;
    }
    int occupied = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    if ((((opq_fab1 * opq_fab1) % 4) == 2)) {
        { int jv_a0e2e = opq_fab1 ^ 0xCA3D;
            jv_a0e2e = (jv_a0e2e * 0x19) % 0x7FFFFFFF;
            jv_a0e2e += (jv_a0e2e >> 2) + 0xA9;
          (void)jv_a0e2e; }
    }
    return 0;
}
