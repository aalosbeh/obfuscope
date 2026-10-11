#include <stdio.h>
static volatile int opq_b402 = 7;
static volatile int opq_b402_b = 3;

int main(void) {
    if ((((opq_b402 * (opq_b402 + 1)) % 2) == 0)) { opq_b402_b ^= 0; }
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    if ((((opq_b402 * opq_b402 + opq_b402) % 2) == 0)) { opq_b402_b ^= 0; }
    int n = (int)sizeof(buf) - 1;
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    if ((((opq_b402 * (opq_b402 + 1)) % 2) == 0)) { opq_b402_b ^= 0; }
    long sum = 0;
    for (int i = 0; i < n; i++) sum += buf[i];
    if (((opq_b402 * opq_b402 - opq_b402) % 2 == 0)) { opq_b402_b ^= 0; }
    printf("%s %ld\n", (char *)buf, sum);
    return 0;
}
