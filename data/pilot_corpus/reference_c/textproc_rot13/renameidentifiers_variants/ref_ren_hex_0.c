#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char v_8f79b0[] = "Attack At Dawn, Bring Supplies!";
    long v_c96164 = 0;
    for (int v_c04b68 = 0; v_c04b68 < 2; v_c04b68++) {
        for (char *p = v_8f79b0; *p; p++) { *p = rot(*p); v_c96164 += (unsigned char)*p; }
    }
    printf("%s %ld\n", v_8f79b0, v_c96164);
    return 0;
}
