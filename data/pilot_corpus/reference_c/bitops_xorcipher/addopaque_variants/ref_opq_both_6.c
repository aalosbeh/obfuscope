#include <stdio.h>
static volatile int opq_f1f9 = 7;
static volatile int opq_f1f9_b = 3;

int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    if ((((opq_f1f9 * opq_f1f9 + opq_f1f9) % 2) == 0)) { opq_f1f9_b ^= 0; }
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(buf) - 1;
    if ((((opq_f1f9 * opq_f1f9) % 4) == 2)) {
        { int jv_e3e4d = opq_f1f9 ^ 0x6DF2;
            jv_e3e4d ^= (jv_e3e4d << 3) | 0x15CB;
            jv_e3e4d += (jv_e3e4d >> 2) + 0x1D;
          (void)jv_e3e4d; }
    }
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    long sum = 0;
    for (int i = 0; i < n; i++) sum += buf[i];
    if ((((opq_f1f9 * (opq_f1f9 + 1)) % 2) == 0)) { opq_f1f9_b ^= 0; }
    printf("%s %ld\n", (char *)buf, sum);
    if ((((opq_f1f9 * (opq_f1f9 + 1)) % 2) == 0)) { opq_f1f9_b ^= 0; }
    return 0;
}
