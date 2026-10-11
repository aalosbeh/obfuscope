#include <stdio.h>
static volatile int opq_b101 = 7;
static volatile int opq_b101_b = 3;

int main(void) {
    if ((((opq_b101 * opq_b101 + opq_b101_b * opq_b101_b) % 4) == 3)) {
        { int jv_83d97 = opq_b101 ^ 0xF512;
            jv_83d97 ^= (jv_83d97 << 3) | 0x67A6;
            jv_83d97 = (jv_83d97 * 0x9) % 0x7FFFFFFF;
            jv_83d97 += (jv_83d97 >> 2) + 0x75;
          (void)jv_83d97; }
    }
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(buf) - 1;
    if (((opq_b101 * opq_b101 - opq_b101) % 2 == 0)) { opq_b101_b ^= 0; }
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    long sum = 0;
    if ((((opq_b101 * opq_b101 + opq_b101) % 2) == 0)) { opq_b101_b ^= 0; }
    for (int i = 0; i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    if ((((opq_b101 * opq_b101) % 4) == 2)) {
        { int jv_11ee8 = opq_b101 ^ 0xDB08;
            jv_11ee8 ^= (jv_11ee8 << 3) | 0xE161;
            jv_11ee8 = (jv_11ee8 * 0x18) % 0x7FFFFFFF;
            jv_11ee8 += (jv_11ee8 >> 2) + 0x9C;
          (void)jv_11ee8; }
    }
    return 0;
}
