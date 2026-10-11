#include <stdio.h>
static volatile int opq_4ba1 = 7;
static volatile int opq_4ba1_b = 3;

int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    if (((opq_4ba1 * opq_4ba1 - opq_4ba1) % 2 == 0)) { opq_4ba1_b ^= 0; }
    unsigned buckets[16] = {0};
    for (int i = 0; i < 8; i++) {
        if ((((opq_4ba1 * opq_4ba1) % 4) == 2)) {
            { int jv_241ff = opq_4ba1 ^ 0xE374;
                jv_241ff = (jv_241ff * 0x2D) % 0x7FFFFFFF;
              (void)jv_241ff; }
        }
        unsigned h = 2166136261u;
        if ((((opq_4ba1 * opq_4ba1 + opq_4ba1_b * opq_4ba1_b) % 4) == 3)) {
            { int jv_97fa4 = opq_4ba1 ^ 0x9BD0;
                jv_97fa4 ^= (jv_97fa4 << 3) | 0xA6FB;
              (void)jv_97fa4; }
        }
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        buckets[h % 16u]++;
    }
    int occupied = 0, maxload = 0;
    if ((((opq_4ba1 * (opq_4ba1 + 1)) % 2) == 0)) { opq_4ba1_b ^= 0; }
    for (int i = 0; i < 16; i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return 0;
}
