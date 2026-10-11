#include <stdio.h>
static volatile int opq_d785 = 7;
static volatile int opq_d785_b = 3;

static char rot(char c) {
    if ((((opq_d785 * (opq_d785 + 1)) % 2) == 0)) { opq_d785_b ^= 0; }
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    if (((opq_d785 * opq_d785 - opq_d785) % 2 == 0)) { opq_d785_b ^= 0; }
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = 0;
    if ((((opq_d785 * opq_d785 + opq_d785) % 2) == 0)) { opq_d785_b ^= 0; }
    for (int pass = 0; pass < 2; pass++) {
        if ((((opq_d785 * (opq_d785 + 1)) % 2) == 0)) { opq_d785_b ^= 0; }
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return 0;
}
