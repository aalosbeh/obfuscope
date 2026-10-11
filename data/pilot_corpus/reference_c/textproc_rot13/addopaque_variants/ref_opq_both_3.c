#include <stdio.h>
static volatile int opq_6926 = 7;
static volatile int opq_6926_b = 3;

static char rot(char c) {
    if ((((opq_6926 * opq_6926 + opq_6926_b * opq_6926_b) % 4) == 3)) {
        { int jv_11270 = opq_6926 ^ 0xDDD5;
            jv_11270 = (jv_11270 * 0xA) % 0x7FFFFFFF;
            jv_11270 += (jv_11270 >> 2) + 0x55;
          (void)jv_11270; }
    }
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if ((((opq_6926 * opq_6926 + opq_6926_b * opq_6926_b) % 4) == 3)) {
        { int jv_c0734 = opq_6926 ^ 0x61E2;
            jv_c0734 = (jv_c0734 * 0x27) % 0x7FFFFFFF;
            jv_c0734 ^= (jv_c0734 << 3) | 0xA473;
          (void)jv_c0734; }
    }
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    if ((((opq_6926 * opq_6926 + opq_6926) % 2) == 0)) { opq_6926_b ^= 0; }
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = 0;
    if (((opq_6926 * opq_6926 - opq_6926) % 2 == 0)) { opq_6926_b ^= 0; }
    for (int pass = 0; pass < 2; pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return 0;
}
