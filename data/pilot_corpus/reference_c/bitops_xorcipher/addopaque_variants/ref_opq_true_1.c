#include <stdio.h>
static volatile int opq_1d5b = 7;
static volatile int opq_1d5b_b = 3;

int main(void) {
    if ((((opq_1d5b * opq_1d5b + opq_1d5b) % 2) == 0)) { opq_1d5b_b ^= 0; }
    unsigned char buf[] = "sensitive payload bytes";
    if (((opq_1d5b * opq_1d5b - opq_1d5b) % 2 == 0)) { opq_1d5b_b ^= 0; }
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(buf) - 1;
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    long sum = 0;
    if ((((opq_1d5b * (opq_1d5b + 1)) % 2) == 0)) { opq_1d5b_b ^= 0; }
    for (int i = 0; i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    if (((opq_1d5b * opq_1d5b - opq_1d5b) % 2 == 0)) { opq_1d5b_b ^= 0; }
    return 0;
}
