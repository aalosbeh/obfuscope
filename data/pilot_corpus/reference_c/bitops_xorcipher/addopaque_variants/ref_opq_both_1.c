#include <stdio.h>
static volatile int opq_8182 = 7;
static volatile int opq_8182_b = 3;

int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    if ((((opq_8182 * opq_8182 + opq_8182_b * opq_8182_b) % 4) == 3)) {
        { int jv_bcc5e = opq_8182 ^ 0xB30F;
            jv_bcc5e ^= (jv_bcc5e << 3) | 0x2228;
          (void)jv_bcc5e; }
    }
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(buf) - 1;
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    if ((((opq_8182 * opq_8182 + opq_8182_b * opq_8182_b) % 4) == 3)) {
        { int jv_31b5b = opq_8182 ^ 0x292F;
            jv_31b5b ^= (jv_31b5b << 3) | 0x765E;
          (void)jv_31b5b; }
    }
    long sum = 0;
    for (int i = 0; i < n; i++) sum += buf[i];
    if ((((opq_8182 * opq_8182) % 4) == 2)) {
        { int jv_fe125 = opq_8182 ^ 0x799;
            jv_fe125 = (jv_fe125 * 0xE) % 0x7FFFFFFF;
          (void)jv_fe125; }
    }
    printf("%s %ld\n", (char *)buf, sum);
    if ((((opq_8182 * opq_8182 + opq_8182_b * opq_8182_b) % 4) == 3)) {
        { int jv_fb056 = opq_8182 ^ 0xB0E0;
            jv_fb056 += (jv_fb056 >> 2) + 0x48;
            jv_fb056 = (jv_fb056 * 0x39) % 0x7FFFFFFF;
          (void)jv_fb056; }
    }
    return 0;
}
