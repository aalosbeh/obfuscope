#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char v_853074[] = "Attack At Dawn, Bring Supplies!";
    long v_5e8622 = 0;
    for (int v_562b54 = 0; v_562b54 < 2; v_562b54++) {
        for (char *p = v_853074; *p; p++) { *p = rot(*p); v_5e8622 += (unsigned char)*p; }
    }
    printf("%s %ld\n", v_853074, v_5e8622);
    return 0;
}
