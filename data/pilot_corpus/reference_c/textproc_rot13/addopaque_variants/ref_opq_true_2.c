#include <stdio.h>
static volatile int opq_3294 = 7;
static volatile int opq_3294_b = 3;

static char rot(char c) {
    if (((opq_3294 * opq_3294 - opq_3294) % 2 == 0)) { opq_3294_b ^= 0; }
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    if (((opq_3294 * opq_3294 - opq_3294) % 2 == 0)) { opq_3294_b ^= 0; }
    char buf[] = "Attack At Dawn, Bring Supplies!";
    if ((((opq_3294 * (opq_3294 + 1)) % 2) == 0)) { opq_3294_b ^= 0; }
    long acc = 0;
    if (((opq_3294 * opq_3294 - opq_3294) % 2 == 0)) { opq_3294_b ^= 0; }
    for (int pass = 0; pass < 2; pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return 0;
}
