#include <stdio.h>
static volatile int opq_2733 = 7;
static volatile int opq_2733_b = 3;

int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[16] = {0};
    if ((((opq_2733 * opq_2733) % 4) == 2)) {
        { int jv_a9b5e = opq_2733 ^ 0x82EE;
            jv_a9b5e += (jv_a9b5e >> 2) + 0x15;
          (void)jv_a9b5e; }
    }
    for (int i = 0; i < 8; i++) {
        if ((((opq_2733 * opq_2733 + opq_2733_b * opq_2733_b) % 4) == 3)) {
            { int jv_b4397 = opq_2733 ^ 0x451F;
                jv_b4397 = (jv_b4397 * 0x2F) % 0x7FFFFFFF;
                jv_b4397 += (jv_b4397 >> 2) + 0xF6;
                jv_b4397 ^= (jv_b4397 << 3) | 0x19A;
              (void)jv_b4397; }
        }
        unsigned h = 2166136261u;
        if ((((opq_2733 * (opq_2733 + 1)) % 2) == 0)) { opq_2733_b ^= 0; }
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        buckets[h % 16u]++;
    }
    int occupied = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    if (((opq_2733 * opq_2733 - opq_2733) % 2 == 0)) { opq_2733_b ^= 0; }
    return 0;
}
