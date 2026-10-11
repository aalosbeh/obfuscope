#include <stdio.h>
static volatile int opq_9e33 = 7;
static volatile int opq_9e33_b = 3;

int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    if ((((opq_9e33 * opq_9e33) % 4) == 2)) {
        { int jv_109e1 = opq_9e33 ^ 0x21E2;
            jv_109e1 = (jv_109e1 * 0x11) % 0x7FFFFFFF;
            jv_109e1 ^= (jv_109e1 << 3) | 0xD089;
          (void)jv_109e1; }
    }
    int n = (int)sizeof(buf) - 1;
    if ((((opq_9e33 * opq_9e33 + opq_9e33_b * opq_9e33_b) % 4) == 3)) {
        { int jv_a940e = opq_9e33 ^ 0xCD8;
            jv_a940e += (jv_a940e >> 2) + 0x4;
            jv_a940e = (jv_a940e * 0xF) % 0x7FFFFFFF;
          (void)jv_a940e; }
    }
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    if ((((opq_9e33 * opq_9e33 + opq_9e33_b * opq_9e33_b) % 4) == 3)) {
        { int jv_ca9f4 = opq_9e33 ^ 0x56E6;
            jv_ca9f4 += (jv_ca9f4 >> 2) + 0x84;
            jv_ca9f4 ^= (jv_ca9f4 << 3) | 0xF5EC;
          (void)jv_ca9f4; }
    }
    long sum = 0;
    if ((((opq_9e33 * opq_9e33) % 4) == 2)) {
        { int jv_35dfc = opq_9e33 ^ 0x4E59;
            jv_35dfc = (jv_35dfc * 0x1F) % 0x7FFFFFFF;
            jv_35dfc += (jv_35dfc >> 2) + 0xD6;
            jv_35dfc ^= (jv_35dfc << 3) | 0xC545;
          (void)jv_35dfc; }
    }
    for (int i = 0; i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return 0;
}
