#include <stdio.h>
static volatile int opq_6487 = 7;
static volatile int opq_6487_b = 3;

int main(void) {
    if ((((opq_6487 * opq_6487) % 4) == 2)) {
        { int jv_6ada9 = opq_6487 ^ 0x11A7;
            jv_6ada9 ^= (jv_6ada9 << 3) | 0xA530;
            jv_6ada9 = (jv_6ada9 * 0x7) % 0x7FFFFFFF;
          (void)jv_6ada9; }
    }
    unsigned char buf[] = "sensitive payload bytes";
    if ((((opq_6487 * opq_6487) % 4) == 2)) {
        { int jv_ec636 = opq_6487 ^ 0xD4E5;
            jv_ec636 = (jv_ec636 * 0x9) % 0x7FFFFFFF;
            jv_ec636 ^= (jv_ec636 << 3) | 0x79CC;
            jv_ec636 += (jv_ec636 >> 2) + 0xB2;
          (void)jv_ec636; }
    }
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(buf) - 1;
    if (((opq_6487 * opq_6487 - opq_6487) % 2 == 0)) { opq_6487_b ^= 0; }
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    long sum = 0;
    for (int i = 0; i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    if ((((opq_6487 * opq_6487) % 4) == 2)) {
        { int jv_e8730 = opq_6487 ^ 0xF8EF;
            jv_e8730 ^= (jv_e8730 << 3) | 0xE3EB;
            jv_e8730 += (jv_e8730 >> 2) + 0xF;
            jv_e8730 = (jv_e8730 * 0x37) % 0x7FFFFFFF;
          (void)jv_e8730; }
    }
    return 0;
}
