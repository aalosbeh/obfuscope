#include <stdio.h>
static volatile int opq_cca1 = 7;
static volatile int opq_cca1_b = 3;

int main(void) {
    if ((((opq_cca1 * opq_cca1 + opq_cca1_b * opq_cca1_b) % 4) == 3)) {
        { int jv_2602e = opq_cca1 ^ 0x92BB;
            jv_2602e ^= (jv_2602e << 3) | 0x6CA;
            jv_2602e = (jv_2602e * 0x34) % 0x7FFFFFFF;
          (void)jv_2602e; }
    }
    unsigned char buf[] = "sensitive payload bytes";
    if ((((opq_cca1 * opq_cca1) % 4) == 2)) {
        { int jv_17ae9 = opq_cca1 ^ 0x6D9C;
            jv_17ae9 += (jv_17ae9 >> 2) + 0x45;
          (void)jv_17ae9; }
    }
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(buf) - 1;
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    if ((((opq_cca1 * opq_cca1) % 4) == 2)) {
        { int jv_1d7b8 = opq_cca1 ^ 0x7DDA;
            jv_1d7b8 += (jv_1d7b8 >> 2) + 0xCF;
          (void)jv_1d7b8; }
    }
    long sum = 0;
    if ((((opq_cca1 * opq_cca1 + opq_cca1_b * opq_cca1_b) % 4) == 3)) {
        { int jv_5b07f = opq_cca1 ^ 0xC270;
            jv_5b07f = (jv_5b07f * 0x33) % 0x7FFFFFFF;
            jv_5b07f ^= (jv_5b07f << 3) | 0xA637;
          (void)jv_5b07f; }
    }
    for (int i = 0; i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return 0;
}
