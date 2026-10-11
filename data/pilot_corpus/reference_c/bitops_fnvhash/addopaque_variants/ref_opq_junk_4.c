#include <stdio.h>
static volatile int opq_b39c = 7;
static volatile int opq_b39c_b = 3;

int main(void) {
    if ((((opq_b39c * opq_b39c + opq_b39c_b * opq_b39c_b) % 4) == 3)) {
        { int jv_aa6e8 = opq_b39c ^ 0x3E38;
            jv_aa6e8 ^= (jv_aa6e8 << 3) | 0x805C;
          (void)jv_aa6e8; }
    }
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    if ((((opq_b39c * opq_b39c + opq_b39c_b * opq_b39c_b) % 4) == 3)) {
        { int jv_48723 = opq_b39c ^ 0x4981;
            jv_48723 = (jv_48723 * 0x32) % 0x7FFFFFFF;
            jv_48723 ^= (jv_48723 << 3) | 0x33C9;
          (void)jv_48723; }
    }
    unsigned buckets[16] = {0};
    for (int i = 0; i < 8; i++) {
        if ((((opq_b39c * opq_b39c) % 4) == 2)) {
            { int jv_be74a = opq_b39c ^ 0xC159;
                jv_be74a = (jv_be74a * 0x2A) % 0x7FFFFFFF;
                jv_be74a ^= (jv_be74a << 3) | 0xCBBA;
              (void)jv_be74a; }
        }
        unsigned h = 2166136261u;
        if ((((opq_b39c * opq_b39c + opq_b39c_b * opq_b39c_b) % 4) == 3)) {
            { int jv_68dd6 = opq_b39c ^ 0x7CF5;
                jv_68dd6 += (jv_68dd6 >> 2) + 0xF7;
                jv_68dd6 ^= (jv_68dd6 << 3) | 0x502C;
                jv_68dd6 = (jv_68dd6 * 0x17) % 0x7FFFFFFF;
              (void)jv_68dd6; }
        }
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        buckets[h % 16u]++;
    }
    int occupied = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return 0;
}
