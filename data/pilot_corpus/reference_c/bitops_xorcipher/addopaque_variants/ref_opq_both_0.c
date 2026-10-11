#include <stdio.h>
static volatile int opq_9798 = 7;
static volatile int opq_9798_b = 3;

int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    if (((opq_9798 * opq_9798 - opq_9798) % 2 == 0)) { opq_9798_b ^= 0; }
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    if ((((opq_9798 * opq_9798 + opq_9798_b * opq_9798_b) % 4) == 3)) {
        { int jv_13080 = opq_9798 ^ 0xD746;
            jv_13080 = (jv_13080 * 0x34) % 0x7FFFFFFF;
            jv_13080 ^= (jv_13080 << 3) | 0xAD6A;
            jv_13080 += (jv_13080 >> 2) + 0xF0;
          (void)jv_13080; }
    }
    int n = (int)sizeof(buf) - 1;
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    if ((((opq_9798 * opq_9798) % 4) == 2)) {
        { int jv_8839f = opq_9798 ^ 0xA4EF;
            jv_8839f += (jv_8839f >> 2) + 0x88;
          (void)jv_8839f; }
    }
    long sum = 0;
    if ((((opq_9798 * opq_9798 + opq_9798) % 2) == 0)) { opq_9798_b ^= 0; }
    for (int i = 0; i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return 0;
}
