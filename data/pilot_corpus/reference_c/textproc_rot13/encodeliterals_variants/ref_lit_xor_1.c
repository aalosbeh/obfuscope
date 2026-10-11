#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0x68A76A9E ^ 0x68A76A93)) % (0x48DF8FA4 ^ 0x48DF8FBE));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0x67BF6AE5 ^ 0x67BF6AE8)) % (0x7875BD9D ^ 0x7875BD87));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0x410041DE ^ 0x410041DE);
    for (int pass = (0x29F553B1 ^ 0x29F553B1); pass < (0x27A908AB ^ 0x27A908A9); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0x6A28E37A ^ 0x6A28E37A);
}
