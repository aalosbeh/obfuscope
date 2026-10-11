#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char oyzakbwnfgbhqatswwl[] = "Attack At Dawn, Bring Supplies!";
    long xhmfjxsnkiivlfzp = 0;
    for (int qxvpssnwelugzvjsugcjs = 0; qxvpssnwelugzvjsugcjs < 2; qxvpssnwelugzvjsugcjs++) {
        for (char *p = oyzakbwnfgbhqatswwl; *p; p++) { *p = rot(*p); xhmfjxsnkiivlfzp += (unsigned char)*p; }
    }
    printf("%s %ld\n", oyzakbwnfgbhqatswwl, xhmfjxsnkiivlfzp);
    return 0;
}
