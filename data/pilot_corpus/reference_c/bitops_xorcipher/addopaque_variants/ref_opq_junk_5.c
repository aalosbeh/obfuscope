#include <stdio.h>
static volatile int opq_9a90 = 7;
static volatile int opq_9a90_b = 3;

int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    if ((((opq_9a90 * opq_9a90 + opq_9a90_b * opq_9a90_b) % 4) == 3)) {
        { int jv_3ce00 = opq_9a90 ^ 0xA691;
            jv_3ce00 += (jv_3ce00 >> 2) + 0x60;
            jv_3ce00 ^= (jv_3ce00 << 3) | 0x6740;
          (void)jv_3ce00; }
    }
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    if ((((opq_9a90 * opq_9a90) % 4) == 2)) {
        { int jv_99397 = opq_9a90 ^ 0x4B13;
            jv_99397 = (jv_99397 * 0x3D) % 0x7FFFFFFF;
            jv_99397 += (jv_99397 >> 2) + 0x62;
          (void)jv_99397; }
    }
    int n = (int)sizeof(buf) - 1;
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    if ((((opq_9a90 * opq_9a90) % 4) == 2)) {
        { int jv_6cbf8 = opq_9a90 ^ 0xDD79;
            jv_6cbf8 ^= (jv_6cbf8 << 3) | 0x372;
            jv_6cbf8 += (jv_6cbf8 >> 2) + 0xB7;
          (void)jv_6cbf8; }
    }
    long sum = 0;
    for (int i = 0; i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    if ((((opq_9a90 * opq_9a90 + opq_9a90_b * opq_9a90_b) % 4) == 3)) {
        { int jv_18554 = opq_9a90 ^ 0x86D6;
            jv_18554 ^= (jv_18554 << 3) | 0xC50F;
            jv_18554 = (jv_18554 * 0x5) % 0x7FFFFFFF;
            jv_18554 += (jv_18554 >> 2) + 0x24;
          (void)jv_18554; }
    }
    return 0;
}
