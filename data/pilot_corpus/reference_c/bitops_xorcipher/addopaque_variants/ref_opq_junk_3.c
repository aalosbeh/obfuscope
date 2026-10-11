#include <stdio.h>
static volatile int opq_3895 = 7;
static volatile int opq_3895_b = 3;

int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    if ((((opq_3895 * opq_3895 + opq_3895_b * opq_3895_b) % 4) == 3)) {
        { int jv_7f9fd = opq_3895 ^ 0x859F;
            jv_7f9fd ^= (jv_7f9fd << 3) | 0x90D4;
          (void)jv_7f9fd; }
    }
    int n = (int)sizeof(buf) - 1;
    if ((((opq_3895 * opq_3895 + opq_3895_b * opq_3895_b) % 4) == 3)) {
        { int jv_7ba7d = opq_3895 ^ 0xA966;
            jv_7ba7d += (jv_7ba7d >> 2) + 0xB0;
            jv_7ba7d = (jv_7ba7d * 0xB) % 0x7FFFFFFF;
            jv_7ba7d ^= (jv_7ba7d << 3) | 0xC5F4;
          (void)jv_7ba7d; }
    }
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    if ((((opq_3895 * opq_3895) % 4) == 2)) {
        { int jv_6c1c2 = opq_3895 ^ 0xD307;
            jv_6c1c2 ^= (jv_6c1c2 << 3) | 0x3DEF;
            jv_6c1c2 = (jv_6c1c2 * 0x17) % 0x7FFFFFFF;
          (void)jv_6c1c2; }
    }
    long sum = 0;
    for (int i = 0; i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    if ((((opq_3895 * opq_3895) % 4) == 2)) {
        { int jv_a85e6 = opq_3895 ^ 0x3B56;
            jv_a85e6 += (jv_a85e6 >> 2) + 0x93;
            jv_a85e6 = (jv_a85e6 * 0x30) % 0x7FFFFFFF;
          (void)jv_a85e6; }
    }
    return 0;
}
