#include <stdio.h>
static volatile int opq_d02f = 7;
static volatile int opq_d02f_b = 3;

static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    if ((((opq_d02f * (opq_d02f + 1)) % 2) == 0)) { opq_d02f_b ^= 0; }
    return c;
}
int main(void) {
    if ((((opq_d02f * opq_d02f + opq_d02f_b * opq_d02f_b) % 4) == 3)) {
        { int jv_159e4 = opq_d02f ^ 0x28C9;
            jv_159e4 += (jv_159e4 >> 2) + 0x94;
            jv_159e4 ^= (jv_159e4 << 3) | 0xE6F2;
          (void)jv_159e4; }
    }
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = 0;
    if (((opq_d02f * opq_d02f - opq_d02f) % 2 == 0)) { opq_d02f_b ^= 0; }
    for (int pass = 0; pass < 2; pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    if ((((opq_d02f * opq_d02f) % 4) == 2)) {
        { int jv_101a3 = opq_d02f ^ 0xD8E0;
            jv_101a3 += (jv_101a3 >> 2) + 0x1;
            jv_101a3 = (jv_101a3 * 0x24) % 0x7FFFFFFF;
            jv_101a3 ^= (jv_101a3 << 3) | 0x5A7F;
          (void)jv_101a3; }
    }
    return 0;
}
