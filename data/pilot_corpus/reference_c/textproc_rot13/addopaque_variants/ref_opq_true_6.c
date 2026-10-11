#include <stdio.h>
static volatile int opq_2032 = 7;
static volatile int opq_2032_b = 3;

static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (((opq_2032 * opq_2032 - opq_2032) % 2 == 0)) { opq_2032_b ^= 0; }
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    if ((((opq_2032 * opq_2032 + opq_2032) % 2) == 0)) { opq_2032_b ^= 0; }
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    if (((opq_2032 * opq_2032 - opq_2032) % 2 == 0)) { opq_2032_b ^= 0; }
    long acc = 0;
    if ((((opq_2032 * opq_2032 + opq_2032) % 2) == 0)) { opq_2032_b ^= 0; }
    for (int pass = 0; pass < 2; pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return 0;
}
