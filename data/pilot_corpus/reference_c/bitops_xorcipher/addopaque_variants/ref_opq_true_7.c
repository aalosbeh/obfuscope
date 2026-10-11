#include <stdio.h>
static volatile int opq_2b91 = 7;
static volatile int opq_2b91_b = 3;

int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    if ((((opq_2b91 * opq_2b91 + opq_2b91) % 2) == 0)) { opq_2b91_b ^= 0; }
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(buf) - 1;
    if (((opq_2b91 * opq_2b91 - opq_2b91) % 2 == 0)) { opq_2b91_b ^= 0; }
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    long sum = 0;
    for (int i = 0; i < n; i++) sum += buf[i];
    if ((((opq_2b91 * (opq_2b91 + 1)) % 2) == 0)) { opq_2b91_b ^= 0; }
    printf("%s %ld\n", (char *)buf, sum);
    if ((((opq_2b91 * opq_2b91 + opq_2b91) % 2) == 0)) { opq_2b91_b ^= 0; }
    return 0;
}
