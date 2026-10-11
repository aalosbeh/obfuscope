#include <stdio.h>
static volatile int opq_83bd = 7;
static volatile int opq_83bd_b = 3;

int main(void) {
    if ((((opq_83bd * opq_83bd + opq_83bd_b * opq_83bd_b) % 4) == 3)) {
        { int jv_c1942 = opq_83bd ^ 0x944E;
            jv_c1942 += (jv_c1942 >> 2) + 0x6D;
            jv_c1942 = (jv_c1942 * 0x5) % 0x7FFFFFFF;
          (void)jv_c1942; }
    }
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    if ((((opq_83bd * opq_83bd) % 4) == 2)) {
        { int jv_d2a55 = opq_83bd ^ 0xEE5;
            jv_d2a55 ^= (jv_d2a55 << 3) | 0xFD81;
            jv_d2a55 += (jv_d2a55 >> 2) + 0xFB;
          (void)jv_d2a55; }
    }
    unsigned buckets[16] = {0};
    if ((((opq_83bd * opq_83bd) % 4) == 2)) {
        { int jv_259d8 = opq_83bd ^ 0x5470;
            jv_259d8 += (jv_259d8 >> 2) + 0x5A;
          (void)jv_259d8; }
    }
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        buckets[h % 16u]++;
    }
    int occupied = 0, maxload = 0;
    if ((((opq_83bd * opq_83bd) % 4) == 2)) {
        { int jv_191c9 = opq_83bd ^ 0xBD4A;
            jv_191c9 += (jv_191c9 >> 2) + 0xC;
            jv_191c9 ^= (jv_191c9 << 3) | 0xEEF9;
          (void)jv_191c9; }
    }
    for (int i = 0; i < 16; i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return 0;
}
