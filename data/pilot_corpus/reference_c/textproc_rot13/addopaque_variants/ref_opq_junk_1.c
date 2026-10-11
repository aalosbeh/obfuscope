#include <stdio.h>
static volatile int opq_6b6f = 7;
static volatile int opq_6b6f_b = 3;

static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if ((((opq_6b6f * opq_6b6f) % 4) == 2)) {
        { int jv_69e0e = opq_6b6f ^ 0xC7CB;
            jv_69e0e = (jv_69e0e * 0x2D) % 0x7FFFFFFF;
            jv_69e0e ^= (jv_69e0e << 3) | 0x170D;
          (void)jv_69e0e; }
    }
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    if ((((opq_6b6f * opq_6b6f + opq_6b6f_b * opq_6b6f_b) % 4) == 3)) {
        { int jv_cee98 = opq_6b6f ^ 0x309F;
            jv_cee98 = (jv_cee98 * 0xB) % 0x7FFFFFFF;
          (void)jv_cee98; }
    }
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    if ((((opq_6b6f * opq_6b6f + opq_6b6f_b * opq_6b6f_b) % 4) == 3)) {
        { int jv_141cd = opq_6b6f ^ 0x2C4D;
            jv_141cd ^= (jv_141cd << 3) | 0xE78A;
            jv_141cd += (jv_141cd >> 2) + 0x90;
          (void)jv_141cd; }
    }
    long acc = 0;
    if ((((opq_6b6f * opq_6b6f) % 4) == 2)) {
        { int jv_21e2d = opq_6b6f ^ 0xD70D;
            jv_21e2d ^= (jv_21e2d << 3) | 0x6A8C;
            jv_21e2d = (jv_21e2d * 0x1F) % 0x7FFFFFFF;
          (void)jv_21e2d; }
    }
    for (int pass = 0; pass < 2; pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return 0;
}
