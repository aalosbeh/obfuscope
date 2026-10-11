#include <stdio.h>
static volatile int opq_fb55 = 7;
static volatile int opq_fb55_b = 3;

int main(void) {
    if ((((opq_fb55 * opq_fb55) % 4) == 2)) {
        { int jv_1d950 = opq_fb55 ^ 0x89B9;
            jv_1d950 += (jv_1d950 >> 2) + 0x91;
            jv_1d950 = (jv_1d950 * 0x15) % 0x7FFFFFFF;
          (void)jv_1d950; }
    }
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(buf) - 1;
    if ((((opq_fb55 * opq_fb55) % 4) == 2)) {
        { int jv_ce9b6 = opq_fb55 ^ 0xFDD9;
            jv_ce9b6 = (jv_ce9b6 * 0x24) % 0x7FFFFFFF;
          (void)jv_ce9b6; }
    }
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    long sum = 0;
    for (int i = 0; i < n; i++) sum += buf[i];
    if ((((opq_fb55 * opq_fb55 + opq_fb55_b * opq_fb55_b) % 4) == 3)) {
        { int jv_a8c65 = opq_fb55 ^ 0x9DAD;
            jv_a8c65 ^= (jv_a8c65 << 3) | 0x35D6;
          (void)jv_a8c65; }
    }
    printf("%s %ld\n", (char *)buf, sum);
    if ((((opq_fb55 * opq_fb55 + opq_fb55_b * opq_fb55_b) % 4) == 3)) {
        { int jv_45fae = opq_fb55 ^ 0x82D7;
            jv_45fae += (jv_45fae >> 2) + 0x3B;
            jv_45fae = (jv_45fae * 0x3D) % 0x7FFFFFFF;
            jv_45fae ^= (jv_45fae << 3) | 0xCC6C;
          (void)jv_45fae; }
    }
    return 0;
}
