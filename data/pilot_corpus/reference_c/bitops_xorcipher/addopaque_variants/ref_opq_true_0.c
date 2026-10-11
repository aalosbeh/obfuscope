#include <stdio.h>
static volatile int opq_cae9 = 7;
static volatile int opq_cae9_b = 3;

int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    if ((((opq_cae9 * opq_cae9 + opq_cae9) % 2) == 0)) { opq_cae9_b ^= 0; }
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(buf) - 1;
    if ((((opq_cae9 * opq_cae9 + opq_cae9) % 2) == 0)) { opq_cae9_b ^= 0; }
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    if (((opq_cae9 * opq_cae9 - opq_cae9) % 2 == 0)) { opq_cae9_b ^= 0; }
    long sum = 0;
    if (((opq_cae9 * opq_cae9 - opq_cae9) % 2 == 0)) { opq_cae9_b ^= 0; }
    for (int i = 0; i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return 0;
}
