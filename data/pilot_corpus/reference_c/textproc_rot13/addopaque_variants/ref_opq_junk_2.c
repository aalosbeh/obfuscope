#include <stdio.h>
static volatile int opq_4fa0 = 7;
static volatile int opq_4fa0_b = 3;

static char rot(char c) {
    if ((((opq_4fa0 * opq_4fa0) % 4) == 2)) {
        { int jv_1fb3c = opq_4fa0 ^ 0x61D3;
            jv_1fb3c ^= (jv_1fb3c << 3) | 0x68A;
            jv_1fb3c += (jv_1fb3c >> 2) + 0x4;
            jv_1fb3c = (jv_1fb3c * 0x36) % 0x7FFFFFFF;
          (void)jv_1fb3c; }
    }
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if ((((opq_4fa0 * opq_4fa0 + opq_4fa0_b * opq_4fa0_b) % 4) == 3)) {
        { int jv_369b9 = opq_4fa0 ^ 0x1E0D;
            jv_369b9 = (jv_369b9 * 0x6) % 0x7FFFFFFF;
          (void)jv_369b9; }
    }
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = 0;
    if ((((opq_4fa0 * opq_4fa0 + opq_4fa0_b * opq_4fa0_b) % 4) == 3)) {
        { int jv_fc98a = opq_4fa0 ^ 0x81FE;
            jv_fc98a += (jv_fc98a >> 2) + 0x99;
            jv_fc98a ^= (jv_fc98a << 3) | 0x815F;
          (void)jv_fc98a; }
    }
    for (int pass = 0; pass < 2; pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    if ((((opq_4fa0 * opq_4fa0) % 4) == 2)) {
        { int jv_6a608 = opq_4fa0 ^ 0x43C9;
            jv_6a608 += (jv_6a608 >> 2) + 0x62;
          (void)jv_6a608; }
    }
    return 0;
}
