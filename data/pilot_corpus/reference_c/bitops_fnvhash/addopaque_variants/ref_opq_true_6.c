#include <stdio.h>
static volatile int opq_ab0a = 7;
static volatile int opq_ab0a_b = 3;

int main(void) {
    if ((((opq_ab0a * (opq_ab0a + 1)) % 2) == 0)) { opq_ab0a_b ^= 0; }
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    if (((opq_ab0a * opq_ab0a - opq_ab0a) % 2 == 0)) { opq_ab0a_b ^= 0; }
    unsigned buckets[16] = {0};
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        buckets[h % 16u]++;
        if ((((opq_ab0a * (opq_ab0a + 1)) % 2) == 0)) { opq_ab0a_b ^= 0; }
    }
    int occupied = 0, maxload = 0;
    if (((opq_ab0a * opq_ab0a - opq_ab0a) % 2 == 0)) { opq_ab0a_b ^= 0; }
    for (int i = 0; i < 16; i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return 0;
}
