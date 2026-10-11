#include <stdio.h>
static volatile int opq_4842 = 7;
static volatile int opq_4842_b = 3;

int main(void) {
    if ((((opq_4842 * (opq_4842 + 1)) % 2) == 0)) { opq_4842_b ^= 0; }
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(buf) - 1;
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    if ((((opq_4842 * (opq_4842 + 1)) % 2) == 0)) { opq_4842_b ^= 0; }
    long sum = 0;
    if (((opq_4842 * opq_4842 - opq_4842) % 2 == 0)) { opq_4842_b ^= 0; }
    for (int i = 0; i < n; i++) sum += buf[i];
    if ((((opq_4842 * opq_4842 + opq_4842_b * opq_4842_b) % 4) == 3)) {
        { int jv_9d931 = opq_4842 ^ 0x62E7;
            jv_9d931 += (jv_9d931 >> 2) + 0x80;
            jv_9d931 ^= (jv_9d931 << 3) | 0x83D3;
          (void)jv_9d931; }
    }
    printf("%s %ld\n", (char *)buf, sum);
    return 0;
}
