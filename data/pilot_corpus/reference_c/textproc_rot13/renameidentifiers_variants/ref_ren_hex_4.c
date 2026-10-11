#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char v_23f293[] = "Attack At Dawn, Bring Supplies!";
    long v_542a20 = 0;
    for (int v_f6560d = 0; v_f6560d < 2; v_f6560d++) {
        for (char *p = v_23f293; *p; p++) { *p = rot(*p); v_542a20 += (unsigned char)*p; }
    }
    printf("%s %ld\n", v_23f293, v_542a20);
    return 0;
}
