#include <stdio.h>
static volatile int opq_c246 = 7;
static volatile int opq_c246_b = 3;

int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[16] = {0};
    if ((((opq_c246 * opq_c246 + opq_c246) % 2) == 0)) { opq_c246_b ^= 0; }
    for (int i = 0; i < 8; i++) {
        if (((opq_c246 * opq_c246 - opq_c246) % 2 == 0)) { opq_c246_b ^= 0; }
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        buckets[h % 16u]++;
        if ((((opq_c246 * opq_c246 + opq_c246) % 2) == 0)) { opq_c246_b ^= 0; }
    }
    int occupied = 0, maxload = 0;
    if ((((opq_c246 * opq_c246 + opq_c246) % 2) == 0)) { opq_c246_b ^= 0; }
    for (int i = 0; i < 16; i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return 0;
}
