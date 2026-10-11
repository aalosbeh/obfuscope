#include <stdio.h>
static volatile int opq_22d7 = 7;
static volatile int opq_22d7_b = 3;

int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    if ((((opq_22d7 * opq_22d7) % 4) == 2)) {
        { int jv_d3f7a = opq_22d7 ^ 0x414C;
            jv_d3f7a += (jv_d3f7a >> 2) + 0x73;
          (void)jv_d3f7a; }
    }
    unsigned buckets[16] = {0};
    if ((((opq_22d7 * opq_22d7) % 4) == 2)) {
        { int jv_282eb = opq_22d7 ^ 0x773F;
            jv_282eb ^= (jv_282eb << 3) | 0xBC57;
            jv_282eb = (jv_282eb * 0xD) % 0x7FFFFFFF;
          (void)jv_282eb; }
    }
    for (int i = 0; i < 8; i++) {
        if ((((opq_22d7 * opq_22d7) % 4) == 2)) {
            { int jv_e5908 = opq_22d7 ^ 0xC8BC;
                jv_e5908 = (jv_e5908 * 0xD) % 0x7FFFFFFF;
              (void)jv_e5908; }
        }
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        buckets[h % 16u]++;
    }
    int occupied = 0, maxload = 0;
    if ((((opq_22d7 * opq_22d7) % 4) == 2)) {
        { int jv_1cfe7 = opq_22d7 ^ 0x3B6A;
            jv_1cfe7 = (jv_1cfe7 * 0x27) % 0x7FFFFFFF;
            jv_1cfe7 ^= (jv_1cfe7 << 3) | 0x5A4E;
          (void)jv_1cfe7; }
    }
    for (int i = 0; i < 16; i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return 0;
}
