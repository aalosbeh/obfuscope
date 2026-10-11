#include <stdio.h>
static volatile int opq_672b = 7;
static volatile int opq_672b_b = 3;

int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[16] = {0};
    if ((((opq_672b * opq_672b + opq_672b_b * opq_672b_b) % 4) == 3)) {
        { int jv_827a6 = opq_672b ^ 0x7B01;
            jv_827a6 += (jv_827a6 >> 2) + 0x8C;
            jv_827a6 ^= (jv_827a6 << 3) | 0xEF00;
          (void)jv_827a6; }
    }
    for (int i = 0; i < 8; i++) {
        if ((((opq_672b * opq_672b) % 4) == 2)) {
            { int jv_ff383 = opq_672b ^ 0x8AA0;
                jv_ff383 = (jv_ff383 * 0x2D) % 0x7FFFFFFF;
                jv_ff383 += (jv_ff383 >> 2) + 0x23;
                jv_ff383 ^= (jv_ff383 << 3) | 0xB6D3;
              (void)jv_ff383; }
        }
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        buckets[h % 16u]++;
        if ((((opq_672b * opq_672b + opq_672b_b * opq_672b_b) % 4) == 3)) {
            { int jv_6a63a = opq_672b ^ 0x9F54;
                jv_6a63a += (jv_6a63a >> 2) + 0x8D;
              (void)jv_6a63a; }
        }
    }
    int occupied = 0, maxload = 0;
    if ((((opq_672b * opq_672b + opq_672b_b * opq_672b_b) % 4) == 3)) {
        { int jv_7242f = opq_672b ^ 0x23B4;
            jv_7242f = (jv_7242f * 0x21) % 0x7FFFFFFF;
            jv_7242f ^= (jv_7242f << 3) | 0xE8A6;
            jv_7242f += (jv_7242f >> 2) + 0x27;
          (void)jv_7242f; }
    }
    for (int i = 0; i < 16; i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf("%d %d\n", occupied, maxload);
    return 0;
}
