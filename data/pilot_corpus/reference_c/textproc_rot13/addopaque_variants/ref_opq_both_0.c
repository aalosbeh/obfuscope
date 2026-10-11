#include <stdio.h>
static volatile int opq_9a72 = 7;
static volatile int opq_9a72_b = 3;

static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    if ((((opq_9a72 * opq_9a72 + opq_9a72_b * opq_9a72_b) % 4) == 3)) {
        { int jv_f5f94 = opq_9a72 ^ 0xD041;
            jv_f5f94 = (jv_f5f94 * 0x7) % 0x7FFFFFFF;
          (void)jv_f5f94; }
    }
    return c;
}
int main(void) {
    if (((opq_9a72 * opq_9a72 - opq_9a72) % 2 == 0)) { opq_9a72_b ^= 0; }
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = 0;
    for (int pass = 0; pass < 2; pass++) {
        if ((((opq_9a72 * opq_9a72 + opq_9a72_b * opq_9a72_b) % 4) == 3)) {
            { int jv_64fa1 = opq_9a72 ^ 0x4C63;
                jv_64fa1 = (jv_64fa1 * 0x20) % 0x7FFFFFFF;
                jv_64fa1 += (jv_64fa1 >> 2) + 0xE7;
              (void)jv_64fa1; }
        }
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    if ((((opq_9a72 * (opq_9a72 + 1)) % 2) == 0)) { opq_9a72_b ^= 0; }
    return 0;
}
