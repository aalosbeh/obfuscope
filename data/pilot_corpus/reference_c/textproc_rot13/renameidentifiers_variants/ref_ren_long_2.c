#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char tpbrshuygitynymkmpv[] = "Attack At Dawn, Bring Supplies!";
    long dfqowzxtogkouemnsbuner = 0;
    for (int jjmkuajnhbtnuy = 0; jjmkuajnhbtnuy < 2; jjmkuajnhbtnuy++) {
        for (char *p = tpbrshuygitynymkmpv; *p; p++) { *p = rot(*p); dfqowzxtogkouemnsbuner += (unsigned char)*p; }
    }
    printf("%s %ld\n", tpbrshuygitynymkmpv, dfqowzxtogkouemnsbuner);
    return 0;
}
