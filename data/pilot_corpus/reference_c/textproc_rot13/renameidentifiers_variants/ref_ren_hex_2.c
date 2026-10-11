#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char v_b8457f[] = "Attack At Dawn, Bring Supplies!";
    long v_abdaa7 = 0;
    for (int v_ee5bff = 0; v_ee5bff < 2; v_ee5bff++) {
        for (char *p = v_b8457f; *p; p++) { *p = rot(*p); v_abdaa7 += (unsigned char)*p; }
    }
    printf("%s %ld\n", v_b8457f, v_abdaa7);
    return 0;
}
