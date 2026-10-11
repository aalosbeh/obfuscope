#include <stdio.h>
static volatile int opq_3966 = 7;
static volatile int opq_3966_b = 3;

static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (((opq_3966 * opq_3966 - opq_3966) % 2 == 0)) { opq_3966_b ^= 0; }
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = 0;
    if (((opq_3966 * opq_3966 - opq_3966) % 2 == 0)) { opq_3966_b ^= 0; }
    for (int pass = 0; pass < 2; pass++) {
        if ((((opq_3966 * opq_3966 + opq_3966) % 2) == 0)) { opq_3966_b ^= 0; }
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    if (((opq_3966 * opq_3966 - opq_3966) % 2 == 0)) { opq_3966_b ^= 0; }
    return 0;
}
