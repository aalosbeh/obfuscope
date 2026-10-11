#include <stdio.h>
static volatile int opq_144e = 7;
static volatile int opq_144e_b = 3;

int main(void) {
    if ((((opq_144e * opq_144e) % 4) == 2)) {
        { int jv_17159 = opq_144e ^ 0xF241;
            jv_17159 += (jv_17159 >> 2) + 0xC0;
            jv_17159 ^= (jv_17159 << 3) | 0xEFF3;
          (void)jv_17159; }
    }
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[16] = {0};
    if ((((opq_144e * opq_144e) % 4) == 2)) {
        { int jv_71351 = opq_144e ^ 0xC54F;
            jv_71351 ^= (jv_71351 << 3) | 0x227B;
          (void)jv_71351; }
    }
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        buckets[h % 16u]++;
        if ((((opq_144e * opq_144e) % 4) == 2)) {
            { int jv_cbd23 = opq_144e ^ 0x4F15;
                jv_cbd23 += (jv_cbd23 >> 2) + 0xFA;
              (void)jv_cbd23; }
        }
    }
    int occupied = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    if ((((opq_144e * opq_144e + opq_144e_b * opq_144e_b) % 4) == 3)) {
        { int jv_e3ae2 = opq_144e ^ 0xEB66;
            jv_e3ae2 += (jv_e3ae2 >> 2) + 0x33;
            jv_e3ae2 = (jv_e3ae2 * 0x2C) % 0x7FFFFFFF;
            jv_e3ae2 ^= (jv_e3ae2 << 3) | 0xBE6D;
          (void)jv_e3ae2; }
    }
    return 0;
}
