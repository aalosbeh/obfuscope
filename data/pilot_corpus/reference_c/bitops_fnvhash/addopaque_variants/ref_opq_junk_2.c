#include <stdio.h>
static volatile int opq_205f = 7;
static volatile int opq_205f_b = 3;

int main(void) {
    if ((((opq_205f * opq_205f) % 4) == 2)) {
        { int jv_c8765 = opq_205f ^ 0xF59F;
            jv_c8765 += (jv_c8765 >> 2) + 0x2D;
            jv_c8765 = (jv_c8765 * 0x3D) % 0x7FFFFFFF;
            jv_c8765 ^= (jv_c8765 << 3) | 0x8550;
          (void)jv_c8765; }
    }
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[16] = {0};
    if ((((opq_205f * opq_205f + opq_205f_b * opq_205f_b) % 4) == 3)) {
        { int jv_561a2 = opq_205f ^ 0x318C;
            jv_561a2 += (jv_561a2 >> 2) + 0xBB;
            jv_561a2 ^= (jv_561a2 << 3) | 0xC865;
          (void)jv_561a2; }
    }
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        if ((((opq_205f * opq_205f) % 4) == 2)) {
            { int jv_b6aa8 = opq_205f ^ 0x3432;
                jv_b6aa8 += (jv_b6aa8 >> 2) + 0xDE;
                jv_b6aa8 = (jv_b6aa8 * 0x23) % 0x7FFFFFFF;
              (void)jv_b6aa8; }
        }
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        buckets[h % 16u]++;
        if ((((opq_205f * opq_205f) % 4) == 2)) {
            { int jv_c1625 = opq_205f ^ 0xBD2C;
                jv_c1625 += (jv_c1625 >> 2) + 0xA2;
                jv_c1625 ^= (jv_c1625 << 3) | 0x73;
                jv_c1625 = (jv_c1625 * 0x11) % 0x7FFFFFFF;
              (void)jv_c1625; }
        }
    }
    int occupied = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return 0;
}
