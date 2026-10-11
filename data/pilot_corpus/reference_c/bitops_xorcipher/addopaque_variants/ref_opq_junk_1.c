#include <stdio.h>
static volatile int opq_3fbd = 7;
static volatile int opq_3fbd_b = 3;

int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    if ((((opq_3fbd * opq_3fbd + opq_3fbd_b * opq_3fbd_b) % 4) == 3)) {
        { int jv_979d9 = opq_3fbd ^ 0xFF91;
            jv_979d9 ^= (jv_979d9 << 3) | 0x5098;
            jv_979d9 += (jv_979d9 >> 2) + 0xA7;
            jv_979d9 = (jv_979d9 * 0x10) % 0x7FFFFFFF;
          (void)jv_979d9; }
    }
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(buf) - 1;
    if ((((opq_3fbd * opq_3fbd + opq_3fbd_b * opq_3fbd_b) % 4) == 3)) {
        { int jv_dfbe2 = opq_3fbd ^ 0xB8E7;
            jv_dfbe2 += (jv_dfbe2 >> 2) + 0x85;
            jv_dfbe2 ^= (jv_dfbe2 << 3) | 0xA366;
            jv_dfbe2 = (jv_dfbe2 * 0x3E) % 0x7FFFFFFF;
          (void)jv_dfbe2; }
    }
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    if ((((opq_3fbd * opq_3fbd + opq_3fbd_b * opq_3fbd_b) % 4) == 3)) {
        { int jv_f95d3 = opq_3fbd ^ 0x4477;
            jv_f95d3 += (jv_f95d3 >> 2) + 0xEA;
          (void)jv_f95d3; }
    }
    long sum = 0;
    for (int i = 0; i < n; i++) sum += buf[i];
    if ((((opq_3fbd * opq_3fbd + opq_3fbd_b * opq_3fbd_b) % 4) == 3)) {
        { int jv_245cb = opq_3fbd ^ 0xC84D;
            jv_245cb = (jv_245cb * 0x9) % 0x7FFFFFFF;
            jv_245cb ^= (jv_245cb << 3) | 0xBE13;
            jv_245cb += (jv_245cb >> 2) + 0xA4;
          (void)jv_245cb; }
    }
    printf("%s %ld\n", (char *)buf, sum);
    return 0;
}
