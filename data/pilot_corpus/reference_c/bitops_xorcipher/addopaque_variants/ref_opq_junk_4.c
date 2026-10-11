#include <stdio.h>
static volatile int opq_b39f = 7;
static volatile int opq_b39f_b = 3;

int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    if ((((opq_b39f * opq_b39f + opq_b39f_b * opq_b39f_b) % 4) == 3)) {
        { int jv_d283c = opq_b39f ^ 0xA93;
            jv_d283c += (jv_d283c >> 2) + 0xF0;
          (void)jv_d283c; }
    }
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(buf) - 1;
    if ((((opq_b39f * opq_b39f) % 4) == 2)) {
        { int jv_1a945 = opq_b39f ^ 0xAA8B;
            jv_1a945 ^= (jv_1a945 << 3) | 0xF1E;
          (void)jv_1a945; }
    }
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    if ((((opq_b39f * opq_b39f) % 4) == 2)) {
        { int jv_5b60c = opq_b39f ^ 0x58D6;
            jv_5b60c ^= (jv_5b60c << 3) | 0x2E4F;
            jv_5b60c += (jv_5b60c >> 2) + 0x43;
          (void)jv_5b60c; }
    }
    long sum = 0;
    for (int i = 0; i < n; i++) sum += buf[i];
    if ((((opq_b39f * opq_b39f) % 4) == 2)) {
        { int jv_1f6fb = opq_b39f ^ 0x4174;
            jv_1f6fb += (jv_1f6fb >> 2) + 0x8E;
            jv_1f6fb = (jv_1f6fb * 0xB) % 0x7FFFFFFF;
            jv_1f6fb ^= (jv_1f6fb << 3) | 0x158C;
          (void)jv_1f6fb; }
    }
    printf("%s %ld\n", (char *)buf, sum);
    return 0;
}
