#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char v_3ae5e6[] = "Attack At Dawn, Bring Supplies!";
    long v_c5bd3c = 0;
    for (int v_187dde = 0; v_187dde < 2; v_187dde++) {
        for (char *p = v_3ae5e6; *p; p++) { *p = rot(*p); v_c5bd3c += (unsigned char)*p; }
    }
    printf("%s %ld\n", v_3ae5e6, v_c5bd3c);
    return 0;
}
