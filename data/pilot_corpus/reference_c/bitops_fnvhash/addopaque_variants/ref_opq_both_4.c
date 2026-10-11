#include <stdio.h>
static volatile int opq_9cca = 7;
static volatile int opq_9cca_b = 3;

int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    if ((((opq_9cca * opq_9cca + opq_9cca_b * opq_9cca_b) % 4) == 3)) {
        { int jv_636de = opq_9cca ^ 0xAADD;
            jv_636de ^= (jv_636de << 3) | 0xD53F;
          (void)jv_636de; }
    }
    unsigned buckets[16] = {0};
    if ((((opq_9cca * opq_9cca + opq_9cca_b * opq_9cca_b) % 4) == 3)) {
        { int jv_8f4c4 = opq_9cca ^ 0x85E9;
            jv_8f4c4 = (jv_8f4c4 * 0x6) % 0x7FFFFFFF;
          (void)jv_8f4c4; }
    }
    for (int i = 0; i < 8; i++) {
        if ((((opq_9cca * opq_9cca + opq_9cca_b * opq_9cca_b) % 4) == 3)) {
            { int jv_db75e = opq_9cca ^ 0xDB2F;
                jv_db75e ^= (jv_db75e << 3) | 0x6FD8;
                jv_db75e = (jv_db75e * 0x35) % 0x7FFFFFFF;
                jv_db75e += (jv_db75e >> 2) + 0x92;
              (void)jv_db75e; }
        }
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        buckets[h % 16u]++;
    }
    int occupied = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    if (((opq_9cca * opq_9cca - opq_9cca) % 2 == 0)) { opq_9cca_b ^= 0; }
    return 0;
}
