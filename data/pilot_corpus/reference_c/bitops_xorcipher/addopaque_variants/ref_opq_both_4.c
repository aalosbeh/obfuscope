#include <stdio.h>
static volatile int opq_4e19 = 7;
static volatile int opq_4e19_b = 3;

int main(void) {
    if ((((opq_4e19 * (opq_4e19 + 1)) % 2) == 0)) { opq_4e19_b ^= 0; }
    unsigned char buf[] = "sensitive payload bytes";
    if ((((opq_4e19 * opq_4e19 + opq_4e19_b * opq_4e19_b) % 4) == 3)) {
        { int jv_a7b24 = opq_4e19 ^ 0x58C4;
            jv_a7b24 = (jv_a7b24 * 0x13) % 0x7FFFFFFF;
            jv_a7b24 += (jv_a7b24 >> 2) + 0x82;
            jv_a7b24 ^= (jv_a7b24 << 3) | 0x2D59;
          (void)jv_a7b24; }
    }
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    if (((opq_4e19 * opq_4e19 - opq_4e19) % 2 == 0)) { opq_4e19_b ^= 0; }
    int n = (int)sizeof(buf) - 1;
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    long sum = 0;
    for (int i = 0; i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    if ((((opq_4e19 * opq_4e19) % 4) == 2)) {
        { int jv_3b46c = opq_4e19 ^ 0x1F20;
            jv_3b46c = (jv_3b46c * 0x6) % 0x7FFFFFFF;
            jv_3b46c += (jv_3b46c >> 2) + 0xC4;
          (void)jv_3b46c; }
    }
    return 0;
}
