#include <stdio.h>
static volatile int opq_2e0d = 7;
static volatile int opq_2e0d_b = 3;

int main(void) {
    if ((((opq_2e0d * opq_2e0d + opq_2e0d_b * opq_2e0d_b) % 4) == 3)) {
        { int jv_c9f18 = opq_2e0d ^ 0x9DB9;
            jv_c9f18 += (jv_c9f18 >> 2) + 0x8A;
            jv_c9f18 ^= (jv_c9f18 << 3) | 0xE8CA;
            jv_c9f18 = (jv_c9f18 * 0x5) % 0x7FFFFFFF;
          (void)jv_c9f18; }
    }
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[16] = {0};
    if ((((opq_2e0d * (opq_2e0d + 1)) % 2) == 0)) { opq_2e0d_b ^= 0; }
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        buckets[h % 16u]++;
    }
    int occupied = 0, maxload = 0;
    if ((((opq_2e0d * opq_2e0d + opq_2e0d) % 2) == 0)) { opq_2e0d_b ^= 0; }
    for (int i = 0; i < 16; i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    if ((((opq_2e0d * opq_2e0d + opq_2e0d_b * opq_2e0d_b) % 4) == 3)) {
        { int jv_d2a70 = opq_2e0d ^ 0xF494;
            jv_d2a70 ^= (jv_d2a70 << 3) | 0xF9C2;
            jv_d2a70 += (jv_d2a70 >> 2) + 0xF4;
            jv_d2a70 = (jv_d2a70 * 0x2A) % 0x7FFFFFFF;
          (void)jv_d2a70; }
    }
    return 0;
}
