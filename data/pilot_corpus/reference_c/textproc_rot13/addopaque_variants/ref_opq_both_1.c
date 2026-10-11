#include <stdio.h>
static volatile int opq_4438 = 7;
static volatile int opq_4438_b = 3;

static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (((opq_4438 * opq_4438 - opq_4438) % 2 == 0)) { opq_4438_b ^= 0; }
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    if ((((opq_4438 * opq_4438) % 4) == 2)) {
        { int jv_81131 = opq_4438 ^ 0x2E3C;
            jv_81131 ^= (jv_81131 << 3) | 0xB36;
            jv_81131 = (jv_81131 * 0x38) % 0x7FFFFFFF;
            jv_81131 += (jv_81131 >> 2) + 0x83;
          (void)jv_81131; }
    }
    return c;
}
int main(void) {
    if (((opq_4438 * opq_4438 - opq_4438) % 2 == 0)) { opq_4438_b ^= 0; }
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = 0;
    if ((((opq_4438 * opq_4438 + opq_4438) % 2) == 0)) { opq_4438_b ^= 0; }
    for (int pass = 0; pass < 2; pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return 0;
}
