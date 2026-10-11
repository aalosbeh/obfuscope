#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char v_c5e591[] = "Attack At Dawn, Bring Supplies!";
    long v_f1a54c = 0;
    for (int v_fc0b34 = 0; v_fc0b34 < 2; v_fc0b34++) {
        for (char *p = v_c5e591; *p; p++) { *p = rot(*p); v_f1a54c += (unsigned char)*p; }
    }
    printf("%s %ld\n", v_c5e591, v_f1a54c);
    return 0;
}
