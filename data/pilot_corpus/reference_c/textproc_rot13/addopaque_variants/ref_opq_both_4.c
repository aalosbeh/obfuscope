#include <stdio.h>
static volatile int opq_ce48 = 7;
static volatile int opq_ce48_b = 3;

static char rot(char c) {
    if (((opq_ce48 * opq_ce48 - opq_ce48) % 2 == 0)) { opq_ce48_b ^= 0; }
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if ((((opq_ce48 * opq_ce48 + opq_ce48_b * opq_ce48_b) % 4) == 3)) {
        { int jv_63a8d = opq_ce48 ^ 0x22C9;
            jv_63a8d += (jv_63a8d >> 2) + 0x4F;
            jv_63a8d ^= (jv_63a8d << 3) | 0xECE4;
          (void)jv_63a8d; }
    }
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    if ((((opq_ce48 * opq_ce48 + opq_ce48_b * opq_ce48_b) % 4) == 3)) {
        { int jv_94b02 = opq_ce48 ^ 0x5161;
            jv_94b02 ^= (jv_94b02 << 3) | 0xCB63;
          (void)jv_94b02; }
    }
    long acc = 0;
    if (((opq_ce48 * opq_ce48 - opq_ce48) % 2 == 0)) { opq_ce48_b ^= 0; }
    for (int pass = 0; pass < 2; pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return 0;
}
