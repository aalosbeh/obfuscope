#include <stdio.h>
static volatile int opq_ed81 = 7;
static volatile int opq_ed81_b = 3;

int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[16] = {0};
    if ((((opq_ed81 * opq_ed81 + opq_ed81_b * opq_ed81_b) % 4) == 3)) {
        { int jv_7d4fb = opq_ed81 ^ 0x6BF8;
            jv_7d4fb += (jv_7d4fb >> 2) + 0x2E;
            jv_7d4fb ^= (jv_7d4fb << 3) | 0xA745;
          (void)jv_7d4fb; }
    }
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        if ((((opq_ed81 * (opq_ed81 + 1)) % 2) == 0)) { opq_ed81_b ^= 0; }
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        buckets[h % 16u]++;
    }
    int occupied = 0, maxload = 0;
    if ((((opq_ed81 * opq_ed81 + opq_ed81_b * opq_ed81_b) % 4) == 3)) {
        { int jv_a53bc = opq_ed81 ^ 0x895;
            jv_a53bc = (jv_a53bc * 0x2A) % 0x7FFFFFFF;
            jv_a53bc += (jv_a53bc >> 2) + 0xCE;
          (void)jv_a53bc; }
    }
    for (int i = 0; i < 16; i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    if ((((opq_ed81 * opq_ed81 + opq_ed81) % 2) == 0)) { opq_ed81_b ^= 0; }
    return 0;
}
