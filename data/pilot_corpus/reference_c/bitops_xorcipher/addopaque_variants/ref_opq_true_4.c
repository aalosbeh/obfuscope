#include <stdio.h>
static volatile int opq_c31d = 7;
static volatile int opq_c31d_b = 3;

int main(void) {
    if ((((opq_c31d * (opq_c31d + 1)) % 2) == 0)) { opq_c31d_b ^= 0; }
    unsigned char buf[] = "sensitive payload bytes";
    if ((((opq_c31d * (opq_c31d + 1)) % 2) == 0)) { opq_c31d_b ^= 0; }
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(buf) - 1;
    if (((opq_c31d * opq_c31d - opq_c31d) % 2 == 0)) { opq_c31d_b ^= 0; }
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    long sum = 0;
    for (int i = 0; i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    if (((opq_c31d * opq_c31d - opq_c31d) % 2 == 0)) { opq_c31d_b ^= 0; }
    return 0;
}
