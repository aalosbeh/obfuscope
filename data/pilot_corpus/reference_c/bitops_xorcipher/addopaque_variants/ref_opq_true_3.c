#include <stdio.h>
static volatile int opq_e50f = 7;
static volatile int opq_e50f_b = 3;

int main(void) {
    if ((((opq_e50f * (opq_e50f + 1)) % 2) == 0)) { opq_e50f_b ^= 0; }
    unsigned char buf[] = "sensitive payload bytes";
    if (((opq_e50f * opq_e50f - opq_e50f) % 2 == 0)) { opq_e50f_b ^= 0; }
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(buf) - 1;
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    long sum = 0;
    if (((opq_e50f * opq_e50f - opq_e50f) % 2 == 0)) { opq_e50f_b ^= 0; }
    for (int i = 0; i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    if ((((opq_e50f * (opq_e50f + 1)) % 2) == 0)) { opq_e50f_b ^= 0; }
    return 0;
}
