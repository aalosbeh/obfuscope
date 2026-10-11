#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char v_a46beb[] = "Attack At Dawn, Bring Supplies!";
    long v_b42036 = 0;
    for (int v_7734cc = 0; v_7734cc < 2; v_7734cc++) {
        for (char *p = v_a46beb; *p; p++) { *p = rot(*p); v_b42036 += (unsigned char)*p; }
    }
    printf("%s %ld\n", v_a46beb, v_b42036);
    return 0;
}
