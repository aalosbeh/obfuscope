#include <stdio.h>
static volatile int opq_fea2 = 7;
static volatile int opq_fea2_b = 3;

int main(void) {
    if ((((opq_fea2 * opq_fea2) % 4) == 2)) {
        { int jv_f5cc6 = opq_fea2 ^ 0xCF7B;
            jv_f5cc6 = (jv_f5cc6 * 0x2E) % 0x7FFFFFFF;
            jv_f5cc6 += (jv_f5cc6 >> 2) + 0x79;
          (void)jv_f5cc6; }
    }
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(buf) - 1;
    if ((((opq_fea2 * opq_fea2 + opq_fea2_b * opq_fea2_b) % 4) == 3)) {
        { int jv_896f4 = opq_fea2 ^ 0x4E5;
            jv_896f4 += (jv_896f4 >> 2) + 0x7F;
            jv_896f4 ^= (jv_896f4 << 3) | 0xF5DC;
            jv_896f4 = (jv_896f4 * 0x7) % 0x7FFFFFFF;
          (void)jv_896f4; }
    }
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    if ((((opq_fea2 * opq_fea2 + opq_fea2_b * opq_fea2_b) % 4) == 3)) {
        { int jv_b9633 = opq_fea2 ^ 0xBFC1;
            jv_b9633 = (jv_b9633 * 0x34) % 0x7FFFFFFF;
            jv_b9633 ^= (jv_b9633 << 3) | 0xBE2B;
          (void)jv_b9633; }
    }
    long sum = 0;
    for (int i = 0; i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    if ((((opq_fea2 * opq_fea2 + opq_fea2_b * opq_fea2_b) % 4) == 3)) {
        { int jv_20740 = opq_fea2 ^ 0xC872;
            jv_20740 ^= (jv_20740 << 3) | 0x5CC;
            jv_20740 = (jv_20740 * 0x1D) % 0x7FFFFFFF;
          (void)jv_20740; }
    }
    return 0;
}
