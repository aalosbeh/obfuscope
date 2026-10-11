#include <stdio.h>
static volatile int opq_8465 = 7;
static volatile int opq_8465_b = 3;

int main(void) {
    if ((((opq_8465 * (opq_8465 + 1)) % 2) == 0)) { opq_8465_b ^= 0; }
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    if ((((opq_8465 * opq_8465) % 4) == 2)) {
        { int jv_e6342 = opq_8465 ^ 0xA65A;
            jv_e6342 ^= (jv_e6342 << 3) | 0x9EF;
          (void)jv_e6342; }
    }
    int n = (int)sizeof(buf) - 1;
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    if (((opq_8465 * opq_8465 - opq_8465) % 2 == 0)) { opq_8465_b ^= 0; }
    long sum = 0;
    if ((((opq_8465 * opq_8465) % 4) == 2)) {
        { int jv_ec653 = opq_8465 ^ 0x9B2;
            jv_ec653 = (jv_ec653 * 0xB) % 0x7FFFFFFF;
          (void)jv_ec653; }
    }
    for (int i = 0; i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return 0;
}
