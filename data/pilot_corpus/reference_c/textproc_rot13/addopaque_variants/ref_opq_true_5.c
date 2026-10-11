#include <stdio.h>
static volatile int opq_5253 = 7;
static volatile int opq_5253_b = 3;

static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    if ((((opq_5253 * (opq_5253 + 1)) % 2) == 0)) { opq_5253_b ^= 0; }
    return c;
}
int main(void) {
    if ((((opq_5253 * opq_5253 + opq_5253) % 2) == 0)) { opq_5253_b ^= 0; }
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = 0;
    for (int pass = 0; pass < 2; pass++) {
        if (((opq_5253 * opq_5253 - opq_5253) % 2 == 0)) { opq_5253_b ^= 0; }
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    if ((((opq_5253 * opq_5253 + opq_5253) % 2) == 0)) { opq_5253_b ^= 0; }
    return 0;
}
