#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char inubcmtujulytq[] = "Attack At Dawn, Bring Supplies!";
    long vgngrarwcosdadu = 0;
    for (int srlhqpdvcujinqt = 0; srlhqpdvcujinqt < 2; srlhqpdvcujinqt++) {
        for (char *p = inubcmtujulytq; *p; p++) { *p = rot(*p); vgngrarwcosdadu += (unsigned char)*p; }
    }
    printf("%s %ld\n", inubcmtujulytq, vgngrarwcosdadu);
    return 0;
}
