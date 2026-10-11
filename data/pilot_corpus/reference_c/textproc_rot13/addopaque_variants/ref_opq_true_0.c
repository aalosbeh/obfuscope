#include <stdio.h>
static volatile int opq_1fec = 7;
static volatile int opq_1fec_b = 3;

static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (((opq_1fec * opq_1fec - opq_1fec) % 2 == 0)) { opq_1fec_b ^= 0; }
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    if ((((opq_1fec * (opq_1fec + 1)) % 2) == 0)) { opq_1fec_b ^= 0; }
    long acc = 0;
    if ((((opq_1fec * (opq_1fec + 1)) % 2) == 0)) { opq_1fec_b ^= 0; }
    for (int pass = 0; pass < 2; pass++) {
        if (((opq_1fec * opq_1fec - opq_1fec) % 2 == 0)) { opq_1fec_b ^= 0; }
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return 0;
}
