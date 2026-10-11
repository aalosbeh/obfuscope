#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char hysviojgxivzaakex[] = "Attack At Dawn, Bring Supplies!";
    long mrscdszrkktucsepep = 0;
    for (int uqrmwowmigjxxlw = 0; uqrmwowmigjxxlw < 2; uqrmwowmigjxxlw++) {
        for (char *p = hysviojgxivzaakex; *p; p++) { *p = rot(*p); mrscdszrkktucsepep += (unsigned char)*p; }
    }
    printf("%s %ld\n", hysviojgxivzaakex, mrscdszrkktucsepep);
    return 0;
}
