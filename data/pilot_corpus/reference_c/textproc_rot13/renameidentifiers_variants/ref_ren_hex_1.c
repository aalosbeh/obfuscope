#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char v_85ba80[] = "Attack At Dawn, Bring Supplies!";
    long v_dee1d8 = 0;
    for (int v_1aaad7 = 0; v_1aaad7 < 2; v_1aaad7++) {
        for (char *p = v_85ba80; *p; p++) { *p = rot(*p); v_dee1d8 += (unsigned char)*p; }
    }
    printf("%s %ld\n", v_85ba80, v_dee1d8);
    return 0;
}
