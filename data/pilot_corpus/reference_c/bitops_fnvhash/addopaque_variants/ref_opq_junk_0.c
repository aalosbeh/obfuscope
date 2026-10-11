#include <stdio.h>
static volatile int opq_61de = 7;
static volatile int opq_61de_b = 3;

int main(void) {
    if ((((opq_61de * opq_61de) % 4) == 2)) {
        { int jv_c33da = opq_61de ^ 0x51E;
            jv_c33da ^= (jv_c33da << 3) | 0xF6D4;
            jv_c33da = (jv_c33da * 0x26) % 0x7FFFFFFF;
          (void)jv_c33da; }
    }
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[16] = {0};
    for (int i = 0; i < 8; i++) {
        if ((((opq_61de * opq_61de) % 4) == 2)) {
            { int jv_c0f08 = opq_61de ^ 0xA7A0;
                jv_c0f08 ^= (jv_c0f08 << 3) | 0x57B;
              (void)jv_c0f08; }
        }
        unsigned h = 2166136261u;
        if ((((opq_61de * opq_61de + opq_61de_b * opq_61de_b) % 4) == 3)) {
            { int jv_7796f = opq_61de ^ 0xF143;
                jv_7796f ^= (jv_7796f << 3) | 0xB73F;
                jv_7796f += (jv_7796f >> 2) + 0xFD;
              (void)jv_7796f; }
        }
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        buckets[h % 16u]++;
    }
    int occupied = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    if ((((opq_61de * opq_61de + opq_61de_b * opq_61de_b) % 4) == 3)) {
        { int jv_92ef9 = opq_61de ^ 0x3E81;
            jv_92ef9 ^= (jv_92ef9 << 3) | 0xE01E;
            jv_92ef9 = (jv_92ef9 * 0x3A) % 0x7FFFFFFF;
            jv_92ef9 += (jv_92ef9 >> 2) + 0xE6;
          (void)jv_92ef9; }
    }
    return 0;
}
